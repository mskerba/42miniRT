/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/01 21:36:39 by momeaizi         ###   ########.fr       */
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
	double	**m;

	up = create_tuple(0, 1, 0, 0);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	from = create_tuple(x, y, z, 1);
	x = get_value(s, ',', len) * M_PI;
	y = get_value(s, ',', len) * M_PI;
	z = get_value(s, ' ', len) * M_PI;
	m = rotation_x(x);
	m = matrix_multi(rotation_y(y), m, 4, 4);
	m = matrix_multi(rotation_z(z), m, 4, 4);
	to = create_tuple(from.x + EPSILON, from.y + EPSILON, from.z + EPSILON, 1);
	to = matrix_x_tuple(m, to);
	c->field_of_view = get_value(s, '\n', len) * M_PI / 180.0;
	c->hsize = 1000.0;
	c->vsize = 1000.0;
	pixel_size(c);
	view_transform(c, from, to, up);
	c->inv = inverse_matrix(c->transf);
}
