/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/21 21:55:41 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// t_comp	prepare_computations(t_intersect intersection, t_ray ray)
// {
// 	t_comp	comps;

// 	comps.t = intersection.t;
// 	comps.object = intersection.object;
// 	comps.point = position(ray, intersection.t);
// 	comps.eyev = negate_tuple(*ray.direction);
// 	comps.normalv = normal_at(comps.object, &comps.point);
// 	if (dot_product(comps.normalv, comps.eyev) < 0)
// 	{
// 		comps.inside = true;
// 		comps.normalv = negate_tuple(comps.normalv);
// 	}
// 	else
// 		comps.inside = false;
// 	trim_tuple(&comps.normalv);
// 	trim_tuple(&comps.eyev);
// 	return (comps);
// }

// t_tuple	shade_hit(t_word word, t_comp comps)
// {
// 	return (lighting(comps.obj.m, world.light, comps.point, comps.eyev,
// 			comps.normalv));
// }

t_tuple	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normal)
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

	effective_c = create_tuple(light.intensity.x * material.color.x,
			light.intensity.y * material.color.y, light.intensity.z
			* material.color.z, 1);
	lightv = substract_tuples(light.position, point);
	normalize_tuple(&lightv);
	ambient = scalar_multi(effective_c, material.ambient);
	light_dot_norm = dot_product(lightv, normal);
	if (light_dot_norm < 0)
		return (ambient);
	diffuse = scalar_multi(effective_c, material.diffuse * light_dot_norm);
	reflectv = reflect(negate_tuple(lightv), normal);
	normalize_tuple(&reflectv);
	reflect_dot_eye = dot_product(reflectv, eyev);
	if (reflect_dot_eye <= 0)
		return (add_tuples(ambient, diffuse));
	factor = pow(reflect_dot_eye, material.shininess);
	specular = scalar_multi(light.intensity, material.specular * factor);
	return (add_tuples(ambient, add_tuples(diffuse, specular)));
}

t_intersect	*intersect_world(t_world *world, t_tuple origin, t_tuple p)
{
	t_intersect	*inter = NULL;
	t_object	*obj;
	double		*t;
	double		**trans;
	t_ray		r;

	obj = world->objects;
	while (obj)
	{
		trans = inverse_matrix(obj->t);
		trans = trim_matrix(trans);
		r.origin = matrix_x_tuple(trans, origin);
		r.direction = substract_tuples(p, origin);
		r.direction = matrix_x_tuple(trans, r.direction);
		normalize_tuple(&r.direction);
		t = intersect(r);
		if (t)
		{
			intersections(&inter, obj, r, t[0]);
			if (!compare(t[0], t[1]))
				intersections(&inter, obj, r, t[1]);
			free(t);
		}
		obj = obj->next;
		clear_matrix(trans, 4);
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
	double	**trsp;
	double	**inv;

	inv = inverse_matrix(obj->t);
	trsp = transpose_matrix(inv, 4);
	o_point = matrix_x_tuple(inv, *w_point);
	o_normal = create_tuple(o_point.x, o_point.y, o_point.z, 0);
	w_normal = matrix_x_tuple(trsp, o_normal);
	clear_matrix(inv, 4);
	clear_matrix(trsp, 4);
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

t_intersect	*create_intersect(double t, t_object *obj, t_ray r)
{
	t_intersect	*inter_section;

	inter_section = (t_intersect *)malloc(sizeof(t_intersect));
	inter_section->object = obj;
	inter_section->t = t;
	inter_section->r = r;
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

void	intersections(t_intersect **head, t_object *obj, t_ray r, double t)
{
	t_intersect	*inter_section;
	t_intersect	*curr;
	t_intersect	*prev;

	inter_section = create_intersect(t, obj, r);
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
	double		**tr;
	t_world		world;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "miniRT");
	img.img = mlx_new_image(img.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	tr = scaling(1, 1, 1);
	light.intensity = create_tuple(1.0, 1.0, 1.0, 1.0);
	light.position = create_tuple(0.0, 20.0, -20.0, 1.0);
	world.light = light;
	world.objects = NULL;
	add_object(&world.objects, 's', scaling(1, 1, 1));
	world.objects->m.color = create_tuple(1.0, 0.2, 1, 1);
	world.objects->m.ambient = 0.0;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 1;
	world.objects->m.shininess = 10.0;
	// create another object
	add_object(&world.objects, 's', translation(1.0, 1.0, 1.0));
	world.objects->m.color = create_tuple(1.0, 1, 0.0, 1);
	world.objects->m.ambient = 0.0;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 1;
	world.objects->m.shininess = 10.0;
	add_object(&world.objects, 's', translation(-1.0, -1.0, -1.0));
	world.objects->m.color = create_tuple(1.0, 0.0, 1, 1);
	world.objects->m.ambient = 0.0;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 1;
	world.objects->m.shininess = 10.0;
	draw(&img, &world);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}
