
#include "miniRT.h"

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
		shading = shade_hit(world, &comps);
		color = get_color(shading);
	}
	else
	{
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
