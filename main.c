
#include "miniRT.h"

void	draw(t_data *img, double **tr)
{
	// t_object	*s1 = create_object('s', NULL);
	// t_object	*s1 = create_object('s', tr);
	double		i;
	double		j;
	double		x;
	double		y;
	double		*inter;
	double		scale = 7.0 / 800;
	t_tuple		*position;
	t_tuple		*origin = create_tuple(0, 0, -5, 1);
	t_tuple		*direc;
	t_ray		*r;
	// t_ray		*r1;
	
	i = -1;
	tr = inverse_matrix(tr);
	tr = trim_matrix(tr);
	r = create_ray(matrix_x_tuple(tr, origin), NULL);
	while (++i < 800)
	{
		y = 3.5 - (i * scale);
		j = -1;
		while (++j < 800)
		{
			x = -3.5 + (j * scale);
			position = create_tuple(x, y, 10, 1);
			direc = substract_tuples(position, origin);
			r->direction = direc;
			inter = intersect(r);
			if (inter)
					my_mlx_pixel_put(img, j, i, 0x00FFFFFF);
			// free(position);
			// free(direc);
			// free(r);
			// free(r1->origin);
			// free(r1->direction);
			// free(r1);
		}
	}
	free(origin);
}
