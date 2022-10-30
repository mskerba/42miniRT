/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:50:24 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/30 07:13:50 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_ray	ray_for_pixel(t_camera *c, double px, double py)
{
	t_tuple	pixel;
	t_ray	r;
	double	world_x;
	double	world_y;

	world_x = (px + 0.5) * c->pixel_size;
	world_y = (py + 0.5) * c->pixel_size;
	world_x = c->half_width - world_x;
	world_y = c->half_height - world_y;
	pixel = matrix_x_tuple(c->inv, create_tuple(world_x, world_y, -1.0, 1));
	r.origin = matrix_x_tuple(c->inv, create_tuple(0, 0, 0, 1));
	r.direction = substract_tuples(pixel, r.origin);
	normalize_tuple(&r.direction);
	return (r);
}
