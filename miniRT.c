/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 21:38:27 by momeaizi         ###   ########.fr       */
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
	key = 0;
	img = NULL;
	printf("a key is pressed!\n");
	return (0);
}


void	intersect(t_ray *r)
{
	t_tuple	*s_to_r;
	double	a;
	double	b;
	double	c;
	double	descriminant;

	s_to_r = create_tuple(r->origin->x, r->origin->y, r->origin->z, 0);
	a = dot_product(r->direction, r->direction);
	b = 2 * dot_product(r->direction, s_to_r);
	c = dot_product(s_to_r, s_to_r) - 1;
	descriminant = pow(b, 2) - (4 * a * c);
	
	if (descriminant < 0)
		return ;
	printf("%lf  | %lf\n", (-b - sqrt(descriminant)) / (2 * a), (-b + sqrt(descriminant)) / (2 * a));
}

void	test()
{
	t_tuple	*ori = create_tuple(0, 0, 5, 1);
	t_tuple	*dir = create_tuple(0, 0, 1, 0);
	t_ray	*r = create_ray(ori, dir);

	// display_tuple(position(r, 0));
	// display_tuple(position(r, 1));
	// display_tuple(position(r, -1));
	// display_tuple(position(r, 2.5));
	intersect(r);
	
}

int	main(void)
{
	// t_data	img;

	// img.mlx = mlx_init();
	// img.mlx_win = mlx_new_window(img.mlx, 800, 800, "miniRT");
	// img.img = mlx_new_image(img.mlx, 800, 800);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	// repere(&img);
	test();
	// mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	// mlx_loop(img.mlx);
}