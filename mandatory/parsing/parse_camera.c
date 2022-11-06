/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 12:52:30 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	from_val(char *s, int len)
{	
	double	x;
	double	y;
	double	z;

	x = set_value(s, ',', len, NULL);
	y = set_value(s, ',', len, NULL);
	z = set_value(s, ' ', len, NULL);
	return (create_tuple(x, y, z, 1));
}

t_tuple	to_val(t_tuple from, char *s, int len)
{
	t_tuple	to;
	t_tuple	orient;

	orient = orientation_vec(s, len);
	to = add_tuples(from, orient);
	return (to);
}

void	parse_camera(t_camera *c, char *s, int len)
{
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
	double	range[2];

	range[0] = 0.0;
	range[1] = 360.0;
	from = from_val(s, len);
	up = create_tuple(0.0, 1.0, 0.0, 0.0);
	to = to_val(from, s, len);
	if (compare(to.y - from.y, 1.0))
		up = create_tuple(0.0, 0.0, 1.0, 0.0);
	c->field_of_view = set_value(s, '\n', len, range) * M_PI / 180.0;
	c->hsize = 1000.0;
	c->vsize = 1000.0;
	pixel_size(c);
	view_transform(c, from, to, up);
}
