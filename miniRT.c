/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/09/17 15:11:11 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}





bool	compare(double a, double b)
{
	if (fabs(a - b) < 0.0001)
		return (true);
	return (false);
}

bool	compare1(double a, double b)
{
	if (fabs(a - b) < 1)
		return (true);
	return (false);
}





void	repere(t_data *img)
{
	double	i;
	double	j;
	
	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < 800)
		{
			if (i == 400 || j == 400)
				my_mlx_pixel_put(img, i, j, 0x00FF1000);
		}
	}
}


void	draw(t_data *img, double *vi, double *vj)
{
	double	i;
	double	j;
	double	x;
	double	y;
	double	a;
	double	b;
	double tmp;

	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < 800)
		{
			a = 200;
			b = 200;
			x = (i - 400);
			y = (400 - j);
			tmp = x;
			x = ((vi[0] * x) + (vj[0] * y));
			y = ((vi[1] * tmp) + (vj[1] * y));
			a= ((vi[0] * a) + (vi[1] * b));
			b= ((vj[0] * 100) + (vj[1] * b));
			if (compare1(pow(x - a,2) + pow(y - b,2), pow(70, 2)))
				my_mlx_pixel_put(img, i, j, 0x00FF0000);
		}
	}
}

int	key_hook(int key, t_data *img)
{
	key += 1;
	static double	v[2][2] = {{1, 0}, {0, 1}};
	static double	a = 1;
	static double	b  = 1;

	if (compare(v[0][0], -1) || compare(v[0][0], 1))
			a *= -1;
	if (compare(v[1][0], -1) || compare(v[1][0], 1))
			b *= -1;
	v[0][0] += (0.1 * a);
	v[0][1] += (-0.1* b);
	v[1][0] += (0.1 * b);
	v[1][1] += (0.1 * a);
	draw(img, v[0], v[1]);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "miniRT");
	img.img = mlx_new_image(img.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	repere(&img);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}