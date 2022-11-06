/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:41 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 21:56:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_light	light;
	t_world	world;

	t_tuple	v = create_tuple(0, -1, 1, 0);
	normalize_tuple(&v);
	display_tuple(&v);
	//
	world.light = &light;
	minirt(&world, &mlx, ac, av[1]);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, ON_KEYDOWN, 0L, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, ON_DESTROY, 0L, destroy, &mlx);
	mlx_loop(mlx.mlx);
	//
}
