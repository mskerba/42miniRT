
#include "miniRT.h"

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}


void	draw(t_data *img, t_object *obj, t_light *light)
{
	double		i;
	double		j;
	double		x;
	double		y;
	double		*inter;
	double		scale = 7.0 / 800;
	t_tuple		pos;
	t_tuple		origin = create_tuple(0, 0, -5, 1);
	t_tuple		direc;
	t_ray		r;
	double		**tr;
	t_tuple		normal;
	t_tuple		point;
	int			color;
	
	i = -1;
	tr = inverse_matrix(obj->t);
	tr = trim_matrix(tr);
	origin = matrix_x_tuple(tr, origin);
	r = create_ray(&origin, NULL);
	while (++i < 800)
	{
		y = 3.5 - (i * scale);
		j = -1;
		while (++j < 800)
		{
			x = -3.5 + (j * scale);
			pos = create_tuple(x, y, 10, 1);
			direc = substract_tuples(pos, origin);
			normalize_tuple(&direc);
			direc = matrix_x_tuple(tr, direc);
			r.direction = &direc;
			inter = intersect(r);
			if (inter)
			{
				point = position(r, min(inter[0], inter[1]));
				normal = normal_at(obj, &point);
				color = lighting(obj->m, *light, point, negate_tuple(*r.direction), normal);
				my_mlx_pixel_put(img, j, i, color);
				free(inter);
			}
		}
	}
	clear_matrix(tr, 4);
}
