int	main(void)
{
	t_mlx		img;
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




t_tuple	lighting(t_world *w,t_comp *comps, t_light *light, bool shadowed)
{
	t_tuple	effective_c;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	factor;
	double	reflect_dot_eye;
	double	light_dot_norm;


	effective_c = create_tuple(light->intensity.x * comps->obj->m.color.x, light->intensity.y * comps->obj->m.color.y, light->intensity.z * comps->obj->m.color.z, 1);
	effective_c = multiply_tuple(&light->intensity, &comps->obj->m.color);
	ambient = scalar_multi(effective_c, w->ambient.ambient);
	if (shadowed)
		return (ambient);
	lightv = substract_tuples(light->position, comps->over_point);
	normalize_tuple(&lightv);
	light_dot_norm = dot_product(lightv, comps->normalv);
	if (light_dot_norm < 0)
		return (ambient);
	diffuse = scalar_multi(effective_c, w->diffuse * light_dot_norm);
	reflectv = reflect(negate_tuple(lightv), comps->normalv);
	normalize_tuple(&reflectv);
	reflect_dot_eye = dot_product(reflectv, comps->eyev);
	if (reflect_dot_eye <= 0)
		return (add_tuples(ambient, diffuse));
	factor = pow(reflect_dot_eye, comps->obj->m.shininess);
	specular = scalar_multi(light->intensity, comps->obj->m.specular * factor);
	return (add_tuples(ambient, add_tuples(diffuse, specular)));
}