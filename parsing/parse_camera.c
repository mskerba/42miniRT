/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 09:40:09 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	from_val(char *s, int len)
{	
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	return (create_tuple(x, y, z, 1));
}

t_tuple	to_val(t_tuple from, char *s, int len)
{	
	double	**m;
	t_tuple	to;
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len) * M_PI;
	y = get_value(s, ',', len) * M_PI;
	z = get_value(s, ' ', len) * M_PI;
	m = rotation_x(x);
	m = matrix_multi(rotation_y(y), m, 4, 4);
	m = matrix_multi(rotation_z(z), m, 4, 4);
	to = create_tuple(from.x + EPSILON, from.y + EPSILON, from.z + EPSILON, 1);
	return (matrix_x_tuple(m, to));
}

void	parse_camera(t_camera *c, char *s, int len)
{
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;

	up = create_tuple(0, 1, 0, 0);
	from = from_val(s, len);
	to = to_val(from, s, len);
	c->field_of_view = get_value(s, '\n', len) * M_PI / 180.0;
	c->hsize = 1000.0;
	c->vsize = 1000.0;
	pixel_size(c);
	view_transform(c, from, to, up);
	c->inv = inverse_matrix(c->transf);
}
