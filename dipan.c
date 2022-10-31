int	main(void)
{
	t_data		img;
	t_light		light;
	t_world		world;
	int fd;
	t_camera	*c;
	t_camera	camera;

	camera.field_of_view = M_PI / 3;
	camera.hsize = 1000.0;
	camera.vsize = 1000.0;
	pixel_size(&camera);
	// view_transform(&camera, create_tuple(0, 0, -5.0, 1), create_tuple(0, 0, -5.0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	view_transform(&camera, create_tuple(0.0, 2.0, -50.0, 1), create_tuple(0.0, 0.0, 0.0, 1), create_tuple(0.0, 1.0, 0.0, 0));
	camera.inv = inverse_matrix(camera.transf);
		
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1000, 1000, "miniRT");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// world.objects = NULL;
	

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
	world.objects->m.color = create_tuple(1.0, 1.0, 0.0, 1);
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





	// spheres
	
	// add_object(&world.objects, 's', scaling(1.0, 1.0, 1.0));
	// world.objects->t = matrix_multi(rotation_z(-M_PI / 2), world.objects->t, 4, 4);
	// world.objects->t = matrix_multi(translation(0.0, 0.0, 0.0), world.objects->t, 4, 4);
	// world.objects->inv = inverse_matrix(world.objects->t);
	// world.objects->inv = trim_matrix(world.objects->inv);
	// world.objects->transp = transpose_matrix(world.objects->inv, 4);
	// world.objects->m.color = create_tuple(1.0, 0.0, 0.0, 1);
	// world.objects->m.ambient = 0.6;
	// world.objects->m.diffuse = 0.9;
	// world.objects->m.specular = 0.9;
	// world.objects->m.shininess = 200.0;
	
	// add_object(&world.objects, 's', scaling(1.0, 1.0, 1.0));
	// world.objects->inv = inverse_matrix(world.objects->t);
	// world.objects->inv = trim_matrix(world.objects->inv);
	// world.objects->transp = transpose_matrix(world.objects->inv, 4);
	// world.objects->m.color = create_tuple(0.0, 1.0, 0.0, 1);
	// world.objects->m.ambient = 0.1;
	// world.objects->m.diffuse = 0.9;
	// world.objects->m.specular = 0.9;
	// world.objects->m.shininess = 200.0;
	// world.objects->cyl_max = 1.0;
	// world.objects->cyl_min = 0.0;



	// add_object(&world.objects, 's', translation(-1.5, 2.0, -3.0));
	// world.objects->inv = inverse_matrix(world.objects->t);
	// world.objects->inv = trim_matrix(world.objects->inv);
	// world.objects->transp = transpose_matrix(world.objects->inv, 4);
	// world.objects->m.color = create_tuple(0.0,1.0, 1.0, 1);
	// world.objects->m.ambient = 0.1;
	// world.objects->m.diffuse = 1;
	// world.objects->m.specular = 0.9;
	// world.objects->m.shininess = 200.0;
	c = malloc(sizeof(t_camera));
	fd = open("res", O_RDWR);
	world = parser(&world, c, fd);
	light.intensity = create_tuple(1.0, 1.0, 1.0, 1.0);
	light.position = create_tuple(1, 5.5, -100.0, 1.0);
	world.light = &light;
	render(&img, &world, &camera);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);
}