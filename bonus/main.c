/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:41 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/05 12:45:48 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_light	light;
	t_world	world;

	world.light = &light;
	minirt(&world, &mlx, ac, av[1]);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_hook(mlx.mlx_win, ON_KEYDOWN, 0L, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, ON_DESTROY, 0L, destroy, &mlx);
	mlx_loop(mlx.mlx);
}