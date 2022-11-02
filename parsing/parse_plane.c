/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 14:14:01 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_plan(t_world *w, char *s, int len)
{
	double	x;
	double	y;
	double	z;
	double	**t;
	double	**r;

	t = coordinate(s, len);
	x = get_value(s, ',', len) * M_PI;
	if (x < 0)
		x = (2 * M_PI) + x;
	y = get_value(s, ',', len) * M_PI;
	if (y < 0)
		y = (2 * M_PI) + y;
	z = get_value(s, ' ', len) * M_PI;
	if (z < 0)
		z = (2 * M_PI) + z;
	r = rotation_x(x);
	r = matrix_multi(rotation_y(y), r, 4, 4);
	r = matrix_multi(rotation_z(z), r, 4, 4);
	add_object(&w->objects, 'p', matrix_multi(t, r, 4, 4));
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
}
