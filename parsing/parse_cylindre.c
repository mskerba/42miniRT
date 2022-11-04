/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/04 18:07:49 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_cylindre(t_world *w, char *s, int len)
{
	double	**t;
	double	**r;
	double	a;
	double	y_min;

	t = coordinates(s, len);
	y_min = t[0][3];
	r = orientation(s, len);
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
	w->objects->cyl_min = y_min;
	w->objects->cyl_max = y_min + a;
	phong_value(w, s, len);
}
