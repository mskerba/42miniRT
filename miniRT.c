/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:18:50 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/02 09:24:42 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	minirt(t_mlx *img, int ac, char *s)
{
	t_light		light;
	t_world		world;
	t_camera	c;
	int			fd;

	world.light = &light;
	world.objects = NULL;
	fd = valid_map(ac, s);
	world = parser(&world, &c, fd);
	render(img, &world, &c);
}
