/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:50 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:09:40 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	is_everything_exist(t_world *world, t_camera *c)
{
	if (!c->transf)
		error(NULL, "there is no camera!\n");
	else if (compare(world->light->intensity.x, -1.0))
		error(NULL, "there is no light!\n");
	else if (compare(world->ambient.ambient, -1.0))
		error(NULL, "there is no ambient!\n");
	else if (!world->objects)
		error(NULL, "there is no object!\n");
}

void	minirt(t_world *world, t_mlx *mlx, int ac, char *s)
{
	t_camera	c;
	int			fd;

	c.transf = NULL;
	world->ambient.ambient = -1;
	world->light->intensity = create_tuple(-1.0, -1.0, -1.0, 1.0);
	world->objects = NULL;
	fd = valid_map(ac, s);
	parser(world, &c, get_line(fd), fd);
	is_everything_exist(world, &c);
	create_win_and_img(mlx);
	render(mlx, world, &c);
	clear_matrix(c.transf, 4);
	clear_matrix(c.inv, 4);
}
