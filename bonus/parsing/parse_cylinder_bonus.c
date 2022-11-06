/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 21:58:05 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

void	parse_cylinder(t_world *w, char *s, int len)
{
	double	**t;
	double	**r;
	double	a;
	double	y_min;
	bool	is_y_neg;

	t = coordinates(s, len);
	y_min = t[1][3];
	r = orient_shape(s, len, &is_y_neg);
	t = matrix_multi(t, r);
	a = set_value(s, ' ', len, NULL) / 2.0;
	if (a < 0)
		error(NULL, "invalid value!\n");
	add_object(&w->objects, 'c', t);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	w->objects->radius = a;
	a = set_value(s, ' ', len, NULL);
	if (a < 0)
		error(NULL, "invalid value!\n");
	if (is_y_neg)
		y_min -= a;
	w->objects->cyl_min = y_min;
	w->objects->cyl_max = y_min + a;
	phong_value(w, s, len);
}
