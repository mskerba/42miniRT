/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/01 19:32:31 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_mlx		img;
	t_light		light;
	t_world		world;
	t_camera	c;
	int			fd;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	world.light = &light;
	world.objects = NULL;
	world.ambient.color = create_tuple(1,1,1,1);
	world.ambient.ambient = 0.1;
	world.diffuse = 0.9;
	fd = valid_map(ac, av[1]);
	world = parser(&world, &c, fd);
	 	// add_object(&world.objects, 'p', rotation_z(M_PI / 2));
	 	// world.objects->t = matrix_multi(translation(5, 0.0, 0.0), world.objects->t, 4, 4);
	 	// world.objects->inv = inverse_matrix(world.objects->t);
	 	// world.objects->inv = trim_matrix(world.objects->inv);
	 	// world.objects->transp = transpose_matrix(world.objects->inv, 4);
	 	// world.objects->m.color = create_tuple(1.0, 0.9, 0.9, 1);
	 	// world.objects->m.specular = 0.9;
	 	// world.objects->m.shininess = 200.0;
	render(&img, &world, &c);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, ON_KEYDOWN, 0L, key_hook, &img);
	mlx_hook(img.mlx_win, ON_DESTROY, 0L, destroy, &img);
	mlx_loop(img.mlx);
}
