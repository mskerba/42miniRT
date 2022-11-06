/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:41 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 21:33:50 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int ac, char **av)
{
	// t_mlx	mlx;
	// t_light	light;
	// t_world	world;

	// world.light = &light;
	// minirt(&world, &mlx, ac, av[1]);
	// mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	// mlx_hook(mlx.mlx_win, ON_KEYDOWN, 0L, key_hook, &mlx);
	// mlx_hook(mlx.mlx_win, ON_DESTROY, 0L, destroy, &mlx);
	// mlx_loop(mlx.mlx);
	ac = 1;
	av[0] = "S";
	t_tuple l;

	l = create_tuple(-1,0,1,0.0);
	normalize_tuple(&l);
	display_tuple(&l);
}
