
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

void	draw(t_data *img, t_world *world)
{
	double		i;
	double		j;
	double		x;
	double		y;
	double		scale = 70.0 / 800.0;
	t_tuple		pos;
	t_tuple		origin = create_tuple(0.0, 0.0, -5.0, 1.0);
	t_tuple		normal;
	t_tuple		point;
	t_tuple		light_ing;
	double		color;
	t_intersect	*inter;
	
	i = -1;
	
	while (++i < 800)
	{
		y = 35.0 - (i * scale);
		j = -1;
		while (++j < 800)
		{
			x = -35.0 + (j * scale);
			pos = create_tuple(x, y, 50.0, 1.0);
			inter = intersect_world(world, origin, create_tuple(x, y, 50.0, 1.0));
			if (hit(inter))
			{
				point = position(inter->r, inter->t);
				normal = normal_at(inter->object, &point);
				light_ing = lighting(inter->object->m, world->light, point, negate_tuple(inter->r.direction), normal);
				color = get_color(light_ing);
				my_mlx_pixel_put(img, j, i, color);
				free(inter);
			}
			else
				my_mlx_pixel_put(img, j, i, 0);
		}
	}
}
