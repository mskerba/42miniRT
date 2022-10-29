/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:04:48 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 22:07:32 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	draw(t_data *img, t_world *world, t_camera *c)
{
	double	y;
	double	x;
	t_ray	r;

	y = -1.0;
	while (++y < 1000)
	{
		x = -1.0;
		while (++x < 1000)
		{
			r = ray_for_pixel(c, x, y);
			my_mlx_pixel_put(img, x, y, color_at(world, &r));
		}
	}
}
