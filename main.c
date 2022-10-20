
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

void	draw(t_data *img, t_object *obj, t_light *light)
{
	double		i;
	double		j;
	double		x;
	double		y;
	double		*inter;
	double		scale = 7.0 / 800.0;
	t_tuple		pos;
	t_tuple		origin = create_tuple(0.0, 0.0, -5.0, 1.0);
	t_tuple		direc;
	t_ray		r;
	double		**tr;
	t_tuple		normal;
	t_tuple		point;
	t_tuple		light_ing;
	double			color;
	
	i = -1;
	tr = inverse_matrix(obj->t);
	tr = trim_matrix(tr);
	origin = matrix_x_tuple(tr, origin);
	r = create_ray(&origin, NULL);
	while (++i < 800)
	{
		y = 3.50 - (i * scale);
		j = -1;
		while (++j < 800)
		{
			x = -3.50 + (j * scale);
			pos = create_tuple(x, y, 10.0, 1.0);
			direc = substract_tuples(pos, origin);
			direc = matrix_x_tuple(tr, direc);
			normalize_tuple(&direc);
			r.direction = &direc;
			inter = intersect(r);
			if (inter)
			{
				point = position(r, min(inter[0], inter[1]));
				normal = normal_at(obj, &point);
				light_ing = lighting(obj->m, *light, point, negate_tuple(*r.direction), normal);
				color = get_color(light_ing);
				my_mlx_pixel_put(img, j, i, color);
				free(inter);
			}
			else
				my_mlx_pixel_put(img, j, i, 0);
		}
	}
	clear_matrix(tr, 4);
}
