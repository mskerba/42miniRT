
#include "miniRT.h"

void	draw(t_data *img, double **tr)
{
	double		i;
	double		j;
	double		x;
	double		y;
	double		*inter;
	double		scale = 7.0 / 800;
	t_tuple		position;
	t_tuple		origin = create_tuple(0, 0, -5, 1);
	t_tuple		direc;
	t_ray		r;
	
	i = -1;
	tr = inverse_matrix(tr);
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
			position = create_tuple(x, y, 10, 1);
			direc = substract_tuples(position, origin);
			normalize_tuple(&direc);
			direc = matrix_x_tuple(tr, direc);
			r.direction = &direc;
			inter = intersect(r);
			if (inter)
			{	
				my_mlx_pixel_put(img, j, i, 0x00FFFFFF);
				free(inter);
			}
		}
	}
	clear_matrix(tr, 4);
}
