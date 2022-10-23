
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


int get_color(t_tuple color)
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
	int			color;

	color = 0;
	intersecs = intersect_world(world, r);
	if (hit(intersecs))
	{
		comps = prepare_computations(intersecs, r);
		shading = shade_hit(world, comps);
		color = get_color(shading);
	}
	if (intersecs)
		clear_intersecs(&intersecs);
	return (color);
}


void	draw(t_data *img, t_world *world)
{
	double		i;
	double		j;
	double		x;
	double		y;
	double		scale = 70.0 / 1000.0;
	t_tuple		origin = create_tuple(0.0, 0.0, -5.0, 1.0);
	t_ray		r;
	
	i = -1;
	
	while (++i < 1000)
	{
		y = 35.0 - (i * scale);
		j = -1;
		while (++j < 1000)
		{
			x = -35.0 + (j * scale);
			r.origin = origin;
			r.direction = substract_tuples(create_tuple(x, y, 50.0, 1.0), origin);
			normalize_tuple(&r.direction);
			my_mlx_pixel_put(img, j, i, color_at(world, &r));
		}
	}
}
