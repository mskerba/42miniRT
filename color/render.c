/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:09:53 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/29 16:38:38 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	render(t_data *img, t_world *world, t_camera *c)
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
