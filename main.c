
#include "miniRT.h"

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_color(t_tuple color)
{
	int	r;
	int	g;
	int	b;

	r = (max(min(color.x, 1), 0) * 255);
	g = (max(min(color.y, 1), 0) * 255);
	b = (max(min(color.z, 1), 0) * 255);
	return (r << 16 | g << 8 | b);
}

void	clear_intersecs(t_intersect **intersecs)
{
	t_intersect	*inters;
	t_intersect	*curr;

	inters = *intersecs;
	while (inters)
	{
		curr = inters;
		inters = inters->next;
		free(curr);
	}
}

int	color_at(t_world *world, t_ray *r)
{
	t_comp		comps;
	t_intersect	*intersecs;
	t_tuple		shading;
	t_object	*obj;
	int			color;

	color = 0;
	obj = world->objects;
	intersecs = intersect_world(world, r);
	if (hit(intersecs))
	{
		comps = prepare_computations(intersecs, r);
		shading = shade_hit(world, &comps);
		color = get_color(shading);
	}
	else
	{
		while(world->objects && world->objects->type != 'p')
			world->objects = world->objects->next;
		if (!world->objects)
			return (0);
		intersecs = local_intersect(world, r);
		if (hit(intersecs))
		{
			comps = local_prepare_computations(intersecs, r);
			shading = shade_hit(world, &comps);
			color = get_color(shading);
		}
	}
	if (intersecs)
		clear_intersecs(&intersecs);
	world->objects = obj;
	return (color);
}

void	draw(t_data *img, t_world *world, t_camera *c)
{
	double	y;
	double	x;
	t_ray	r;

	y = -1.0;
	while (++y < 1000)
	{
		x = -1.0;
		while (++x < 1000)
		{
			r = ray_for_pixel(c, x, y);
			my_mlx_pixel_put(img, x, y, color_at(world, &r));
		}
	}
}
