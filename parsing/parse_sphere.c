/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:04 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 12:54:28 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_sphere(t_world *w, char *s, int len)
{
	double	a;
	double	**t;

	t = coordinates(s, len);
	a = set_value(s, ' ', len, NULL) / 2.0;
	if (a < 0)
		error(NULL, "invalid value!\n");
	t = matrix_multi(t, scaling(a, a, a));
	add_object(&w->objects, 's', t);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
}
