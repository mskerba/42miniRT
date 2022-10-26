/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/26 20:23:18 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_shadowed(t_world *world, t_tuple point)
{
	t_ray		r;
	t_tuple		v;
	t_intersect	*intersecs;
	double		distance;
	bool		in_shadow;

	in_shadow = false;
	v = substract_tuples(world->light->position, point);
	distance = magnitude(v);
	normalize_tuple(&v);
	r = create_ray(point, v);
	intersecs = intersect_world(world, &r);
	if (hit(intersecs))
		if (intersecs->t < distance)
			in_shadow = true;
	if (intersecs)
		clear_intersecs(&intersecs);
	return (in_shadow);
}

void	pixel_size(t_camera *c)
{
	double	half_view;
	double	aspect;

	half_view = tan(c->field_of_view / 2.0);
	aspect = c->hsize / c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = 2.0 * (c->half_width / c->hsize);
}

t_comp	prepare_computations(t_intersect *intersecs, t_ray *r)
{
	t_comp	comps;

	comps.t = intersecs->t;
	comps.obj = intersecs->object;
	comps.point = position(*r, comps.t);
	comps.eyev = negate_tuple(r->direction);
	comps.normalv = normal_at(comps.obj, &comps.point);
	comps.over_point = add_tuples(comps.point, scalar_multi(comps.normalv, EPSILON));
	if (compare(dot_product(comps.normalv, comps.eyev), 0))
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = false;
	trim_tuple(&comps.normalv);
	trim_tuple(&comps.eyev);
	return (comps);
}

t_comp	local_prepare_computations(t_intersect *intersecs, t_ray *r)
{
	t_comp	comps;

	comps.t = intersecs->t;
	comps.obj = intersecs->object;
	comps.point = position(*r, comps.t);
	comps.eyev = negate_tuple(r->direction);
	comps.normalv = local_normal_at(comps.obj, &comps.point);
	comps.over_point = add_tuples(comps.point, scalar_multi(comps.normalv, EPSILON));
	if (compare(dot_product(comps.normalv, comps.eyev), 0))
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = false;
	trim_tuple(&comps.normalv);
	trim_tuple(&comps.eyev);
	return (comps);
}

t_tuple	shade_hit(t_world *world, t_comp *comps)
{
	bool	shadowed;
	
	shadowed = is_shadowed(world, comps->over_point);
	return (lighting(comps, world->light, shadowed));
}

t_tuple	lighting(t_comp *comps, t_light *light, bool shadowed)
{
	t_tuple	effective_c;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	factor;
	double	reflect_dot_eye;
	double	light_dot_norm;

	effective_c = create_tuple(light->intensity.x * comps->obj->m.color.x, light->intensity.y * comps->obj->m.color.y, light->intensity.z * comps->obj->m.color.z, 1);
	ambient = scalar_multi(effective_c, comps->obj->m.ambient);
	if (shadowed)
		return (ambient);
	lightv = substract_tuples(light->position, comps->over_point);
	normalize_tuple(&lightv);
	light_dot_norm = dot_product(lightv, comps->normalv);
	if (light_dot_norm < 0)
		return (ambient);
	diffuse = scalar_multi(effective_c, comps->obj->m.diffuse * light_dot_norm);
	reflectv = reflect(negate_tuple(lightv), comps->normalv);
	normalize_tuple(&reflectv);
	reflect_dot_eye = dot_product(reflectv, comps->eyev);
	if (reflect_dot_eye <= 0)
		return (add_tuples(ambient, diffuse));
	factor = pow(reflect_dot_eye, comps->obj->m.shininess);
	specular = scalar_multi(light->intensity, comps->obj->m.specular * factor);
	return (add_tuples(ambient, add_tuples(diffuse, specular)));
}

t_tuple	normal_at(t_object *obj, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	
	o_point = matrix_x_tuple(obj->inv, *w_point);
	o_normal = create_tuple(o_point.x, o_point.y, o_point.z, 0);
	w_normal = matrix_x_tuple(obj->transp, o_normal);
	w_normal.w = 0;
	normalize_tuple(&w_normal);
	return (w_normal);
}

t_tuple	local_normal_at(t_object *obj, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	
	o_point = matrix_x_tuple(obj->inv, *w_point);
	o_normal = create_tuple(0, 1, 0, 0);
	w_normal = matrix_x_tuple(obj->transp, o_normal);
	w_normal.w = 0;
	normalize_tuple(&w_normal);
	return (w_normal);
}

t_tuple	reflect(t_tuple lightv, t_tuple normal)
{
	t_tuple	reflect;
	double	dot;

	dot = 2 * dot_product(lightv, normal);
	reflect = scalar_multi(normal, dot);
	reflect = substract_tuples(lightv, reflect);
	return (reflect);
}

int	main(void)
{
	t_data		img;
	t_light		light;
	t_world		world;
	t_camera	c;

	c.field_of_view = 3.1415926 / 3;
	c.hsize = 1000.0;
	c.vsize = 1000.0;
	pixel_size(&c);
	c.transf = view_transform(create_tuple(0, 1.5, -5.0, 1), create_tuple(0.0, 2.0, .0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	c.inv = inverse_matrix(c.transf);
		
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	light.intensity = create_tuple(1.0, 1.0, 1.0, 1.0);
	light.position = create_tuple(0.0, 10.0, -10.0, 1.0);
	world.light = &light;
	world.objects = NULL;
	

	//walls
	add_object(&world.objects, 'p', rotation_z(-M_PI / 2));
	world.objects->t = matrix_multi(translation(-5, 0.0, 0.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.9, 0.9, 1);
	world.objects->m.ambient = 0.5;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.0;
	world.objects->m.shininess = 200.0;

	
	add_object(&world.objects, 'p', translation(0.0, 0.0, 0.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 1.0, 0.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 0.5;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;


	
	add_object(&world.objects, 'p', rotation_z(-M_PI / 2));
	world.objects->t = matrix_multi(translation(5, 0.0, 0.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.2, 0.1, 1);
	world.objects->m.ambient = 0.5;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.0;
	world.objects->m.shininess = 200.0;





	//spheres
	
	add_object(&world.objects, 's', translation(2.0, 1.0, 1.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.0, 0.0, 1);
	world.objects->m.ambient = 0.6;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;
	
	add_object(&world.objects, 's', translation(0.0, 2.0, -1.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 1.0, 0.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;


	add_object(&world.objects, 's', translation(-1.5, 2.0, -3.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0,1.0, 1.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;
	// c.transf = view_transform(create_tuple(0, 1.5, -5.0, 1), create_tuple(0.0, 2.0, .0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	c.inv = inverse_matrix(c.transf);
	draw(&img, &world, &c);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}
