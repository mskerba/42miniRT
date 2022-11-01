/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 23:05:52 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_camera(t_camera *c, char *s, int len)
{
	double	x;
	double	y;
	double	z;
	t_tuple	to;
	t_tuple	from;
	t_tuple	up;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	from = create_tuple(x, y, z, 1);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	to = matrix_x_tuple(rotation_x(x), from);
	to = matrix_x_tuple(rotation_y(y), to);
	to = matrix_x_tuple(rotation_z(z), to);
	up = create_tuple(0, 1, 0, 0);
	display_tuple(&from);
	display_tuple(&to);
	display_tuple(&up);
	c->field_of_view = get_value(s, '\n', len) / 180;
	c->hsize = 1000.0;
	c->vsize = 1000.0;
	pixel_size(c);
	view_transform(c, from, to, up);
	c->inv = inverse_matrix(c->transf);
}
