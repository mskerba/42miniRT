/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/01 19:40:18 by momeaizi         ###   ########.fr       */
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

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	t = translation(x, y, z);
	x = get_value(s, ',', len) * M_PI;
	y = get_value(s, ',', len) * M_PI;
	z = get_value(s, ' ', len) * M_PI;
	r = rotation_x(x);
	r = matrix_multi(rotation_y(y), t, 4, 4);
	r = matrix_multi(rotation_z(z), t, 4, 4);
	add_object(&w->objects, 'p', r);
	w->objects->t = matrix_multi(t, r, 4, 4);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
}
