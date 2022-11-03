/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:41 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 11:40:36 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_mlx	img;
	t_light	light;
	t_world	world;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	world.light = &light;
	minirt(&world, &img, ac, av[1]);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, ON_KEYDOWN, 0L, key_hook, &img);
	mlx_hook(img.mlx_win, ON_DESTROY, 0L, destroy, &img);
	mlx_loop(img.mlx);
}
