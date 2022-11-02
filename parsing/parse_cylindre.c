/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 12:43:34 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_cylindre(t_world *w, char *s, int len)
{
	double	**t;
	double	**tmp;
	double	x;

	tmp = coordinate(s, len);
	x = get_value(s, ',', len) * M_PI;
	t = rotation_x(x);
	x = get_value(s, ',', len) * M_PI;
	t = matrix_multi(rotation_y(x), t, 4, 4);
	x = get_value(s, ' ', len) * M_PI;
	t = matrix_multi(rotation_z(x), t, 4, 4);
	add_object(&w->objects, 'c', matrix_multi(tmp, t, 4, 4));
	x = get_value(s, ' ', len) / 2.0;
	tmp = scaling(x, 1.0, x);
	w->objects->t = matrix_multi(tmp, t, 4, 4);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	x = get_value(s, ' ', len);
	w->objects->cyl_min = -5;
	w->objects->cyl_max = x;
	phong_value(w, s, len);
	clear_matrix(t, 4);
	clear_matrix(tmp, 4);
}
