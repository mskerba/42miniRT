/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/29 10:05:58 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(void)
{
	t_data		img;
	t_light		light;
	t_world		world;
	t_camera	c;

	c.field_of_view = M_PI / 3;
	c.hsize = 1000.0;
	c.vsize = 1000.0;
	pixel_size(&c);
	c.transf = view_transform(create_tuple(0.0, 2.0, -50.0, 1), create_tuple(0.0, 0.0, 0.0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	c.inv = inverse_matrix(c.transf);
		
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	light.intensity = create_tuple(1.0, 1.0, 1.0, 1.0);
	light.position = create_tuple(-4.0, 4.0, -10.0, 1.0);
	world.light = &light;
	world.objects = NULL;
	

	//walls
	add_object(&world.objects, 'p', rotation_z(M_PI / 2));
	world.objects->t = matrix_multi(translation(5, 0.0, 0.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.9, 0.9, 1);
	world.objects->m.ambient = 0.5;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;

	
	add_object(&world.objects, 'p', translation(0.0, 0.0, 0.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 1.0, 0.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 0.5;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;


	
	add_object(&world.objects, 'p', rotation_z(-M_PI / 2));
	world.objects->t = matrix_multi(translation(-5, 0.0, 0.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.0, 0.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 0.5;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;





	//spheres
	
	add_object(&world.objects, 's', scaling(1.0, 1.0, 1.0));
	world.objects->t = matrix_multi(rotation_z(-M_PI / 2), world.objects->t, 4, 4);
	world.objects->t = matrix_multi(translation(0.0, 5.0, 0.0), world.objects->t, 4, 4);
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(1.0, 0.0, 0.0, 1);
	world.objects->m.ambient = 0.6;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;
	
	add_object(&world.objects, 'c', translation(0.0, 2.0, -1.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0, 1.0, 0.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 0.9;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;



	add_object(&world.objects, 's', translation(-1.5, 2.0, -3.0));
	world.objects->inv = inverse_matrix(world.objects->t);
	world.objects->inv = trim_matrix(world.objects->inv);
	world.objects->transp = transpose_matrix(world.objects->inv, 4);
	world.objects->m.color = create_tuple(0.0,1.0, 1.0, 1);
	world.objects->m.ambient = 0.1;
	world.objects->m.diffuse = 1;
	world.objects->m.specular = 0.9;
	world.objects->m.shininess = 200.0;
	

	draw(&img, &world, &c);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}
