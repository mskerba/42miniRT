/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 18:51:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


bool	compare(double a, double b)
{
	if (fabs(a - b) < EPSILON)
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



int	key_hook(int key, t_data *img)
{
	printf("a key is pressed!\n");
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