/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/24 23:10:25 by momeaizi         ###   ########.fr       */
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


t_ray	ray_for_pixel(t_camera *c, double px, double py)
{
	t_tuple	pixel;
	t_ray	r;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = (px + 0.5) * c->pixel_size;
	yoffset = (py + 0.5) * c->pixel_size;
	world_x = c->half_width - xoffset;
	world_y = c->half_height - yoffset;
	pixel = matrix_x_tuple(c->inv, create_tuple(world_x, world_y, -1.0, 1));
	r.origin = matrix_x_tuple(c->inv, create_tuple(0, 0, 0, 1));
	r.direction = substract_tuples(pixel, r.origin);
	normalize_tuple(&r.direction);
	return (r);
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

double	**view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	double **orint;
	double **tr;

	forward = substract_tuples(to, from);
	normalize_tuple(&forward);
	normalize_tuple(&up);
	left = cross_product(forward, up);
	true_up = cross_product(left, forward);
	orint = scaling(left.x, true_up.y, -forward.z);
	orint[0][1] = left.y;
	orint[0][2] = left.z;
	orint[1][0] = true_up.x;
	orint[1][2] = true_up.z;
	orint[2][0] = -forward.x;
	orint[2][1] = -forward.y;
	tr = translation(-from.x, -from.y, -from.z);
	orint = matrix_multi(orint, tr, 4, 4);
	return (orint);
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

t_intersect	*intersect_world(t_world *world, t_ray *r)
{
	t_intersect	*inter;
	t_object	*obj;
	double		*t;
	t_ray		r1;

	inter = NULL;
	obj = world->objects;
	while (obj)
	{
		r1.origin = matrix_x_tuple(obj->inv, r->origin);
		r1.direction = matrix_x_tuple(obj->inv, r->direction);
		normalize_tuple(&r1.direction);
		t = intersect(r1);
		if (t)
		{
			intersections(&inter, obj, t[0]);
			if (!compare(t[0], t[1]))
				intersections(&inter, obj, t[1]);
			free(t);
		}
		obj = obj->next;
	}
	return (inter);
}

double	*intersect(t_ray r)
{
	t_tuple	s_to_r;
	double	a;
	double	b;
	double	c;
	double	descriminant;
	double	*inter;

	// the vector from the sphere's center, to the ray origin
	// remember: the sphere is centered at the world origin
	s_to_r = create_tuple(r.origin.x, r.origin.y, r.origin.z, 0);
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, s_to_r);
	c = dot_product(s_to_r, s_to_r) - 1;
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant < 0)
		return (NULL);
	inter = malloc(2 * sizeof(double));
	inter[0] = (-b - sqrt(descriminant)) / (2 * a);
	inter[1] = (-b + sqrt(descriminant)) / (2 * a);
	return (inter);
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

t_tuple	reflect(t_tuple lightv, t_tuple normal)
{
	t_tuple	reflect;
	double	dot;

	dot = 2 * dot_product(lightv, normal);
	reflect = scalar_multi(normal, dot);
	reflect = substract_tuples(lightv, reflect);
	return (reflect);
}

t_intersect	*create_intersect(double t, t_object *obj)
{
	t_intersect	*inter_section;

	inter_section = (t_intersect *)malloc(sizeof(t_intersect));
	inter_section->object = obj;
	inter_section->t = t;
	inter_section->next = NULL;
	return (inter_section);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

bool	compare(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

int	key_hook(int key, t_data *img)
{
	key = 0;
	img = NULL;
	printf("a key is pressed!\n");
	return (0);
}

void	intersections(t_intersect **head, t_object *obj, double t)
{
	t_intersect	*inter_section;
	t_intersect	*curr;
	t_intersect	*prev;

	inter_section = create_intersect(t, obj);
	if (!*head)
		*head = inter_section;
	else
	{
		curr = *head;
		prev = NULL;
		while (curr && curr->t >= 0 && (t > curr->t || t < 0))
		{
			prev = curr;
			curr = curr->next;
		}
		if (!prev)
		{
			inter_section->next = *head;
			*head = inter_section;
			return ;
		}
		inter_section->next = prev->next;
		prev->next = inter_section;
	}
}

double	**trim_matrix(double **m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (m[i][j] < EPSILON && m[i][j] > -EPSILON)
				m[i][j] = 0.0;
	}
	return (m);
}

void	trim_tuple(t_tuple *tuple)
{
	if (tuple->x < EPSILON && tuple->x > -EPSILON)
		tuple->x = 0.0;
	if (tuple->y < EPSILON && tuple->y > -EPSILON)
		tuple->y = 0.0;
	if (tuple->z < EPSILON && tuple->z > -EPSILON)
		tuple->z = 0.0;
	if (tuple->w < EPSILON && tuple->w > -EPSILON)
		tuple->w = 0.0;
}

void	add_object(t_object **obj, char type, double **t)
{
	static unsigned int	id = 0;
	t_object			*new_obj;

	new_obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return ;
	new_obj->type = type;
	new_obj->id = id;
	new_obj->t = t;
	new_obj->next = *obj;
	*obj = new_obj;
	id++;
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
	c.transf = view_transform(create_tuple(0, 1.5, -5.0, 1), create_tuple(0.0, 1.0, 0.0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	c.inv = inverse_matrix(c.transf);
		
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	light.intensity = create_tuple(1.0, 1.0, 1.0, 1.0);
	light.position = create_tuple(-10.0, 10.0, -10.0, 1.0);
	world.light = &light;
	world.objects = NULL;
	

	//walls
	add_object(&world.objects, 's', scaling(10.0, 0.01, 10.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.9, 0.9, 1);
	world.objects->m.ambient = 0.01;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.0;
	world.objects->m.shininess = 200.0;


	add_object(&world.objects, 's', scaling(10.0, 0.001, 10.0));
	world.objects->t = matrix_multi(rotation_x(3.14 / 2.0) , world.objects->t, 4, 4);
	world.objects->t = matrix_multi(rotation_y(-3.14 / 4.0) , world.objects->t, 4, 4);
	world.objects->t = matrix_multi(translation(0.0, 0.0, 5.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 1, 1, 1);
	world.objects->m.ambient = 1.0;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.0;
	world.objects->m.shininess = 200.0;


	
	add_object(&world.objects, 's', scaling(10.0, 0.001, 10.0));
	world.objects->t = matrix_multi(rotation_x(3.14 / 2.0) , world.objects->t, 4, 4);
	world.objects->t = matrix_multi(rotation_y(3.14 / 4.0) , world.objects->t, 4, 4);
	world.objects->t = matrix_multi(translation(0.0, 0.0, 5.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 0, 1, 1);
	world.objects->m.ambient = 1.0;
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
	


	add_object(&world.objects, 's', translation(-2.2, 2.0, -3.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 0.0, 1.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 1;
	world.objects->m.shininess = 10.0;

	draw(&img, &world, &c);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}
