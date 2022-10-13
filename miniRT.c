/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/13 08:01:02 by mskerba          ###   ########.fr       */
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


t_intersect	*create_intersect(double t, char type)
{
	t_intersect	*inter_section;

	inter_section = (t_intersect *)malloc(sizeof(t_intersect));
	inter_section->object = create_object(type);
	inter_section->t = t;
	inter_section->next = NULL;
	return (inter_section);
}



void	test()
{
	t_tuple	*ori = create_tuple(0, 0, 5, 1);
	t_tuple	*dir = create_tuple(0, 0, 1, 0);
	t_ray	*r = create_ray(ori, dir);

	t_object	*sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	sphere = create_object('s');
	printf("%d\n", sphere->id);
	intersect(r);
	
}

void	intersections(t_intersect **head, double t, char type)
{
	t_intersect	*inter_section;
	t_intersect	*curr;
	t_intersect	*prev;

	inter_section = create_intersect(t, type);
	if (!*head)
		*head = inter_section;
	else
	{
		curr = *head;
		prev = NULL;
		while (curr && curr->t >= 0 && (t > curr->t || t < 0))
		{
			prev = curr;
			curr = curr->next;
		}
		if(!prev)
		{
			inter_section->next = *head;
			*head = inter_section;
			return ;
		}
		inter_section->next = prev->next;
		prev->next = inter_section;
	}
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "miniRT");
	img.img = mlx_new_image(img.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	repere(&img);
	test();
	mlx_hook(img.mlx_win, 02, 0L, key_hook, &img);
	mlx_loop(img.mlx);


	t_intersect	*head = NULL;

	intersections(&head, 9, 's');
	intersections(&head, 3, 's');
	intersections(&head, -2, 's');
	intersections(&head, 0, 's');
	intersections(&head, 7, 's');
	intersections(&head, 2, 's');
	intersections(&head, -9, 's');
	intersections(&head, 6, 's');
	intersections(&head, 4, 's');
	intersections(&head, 14, 's');
	intersections(&head, 19, 's');
	intersections(&head, 20, 's');
	while (head)
	{
		printf("t : %lf\n", head->t);
		printf("s : %c\n", head->object->type);
		printf("----------------\n");
		head = head->next;
	}
}
