/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:04 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 09:40:34 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_sphere(t_world *w, char *s, int len)
{
	double	x;
	double	**t;
	double	**tmp;

	t = coordinate(s, len);
	add_object(&w->objects, 's', t);
	x = get_value(s, ' ', len) / 2.0;
	tmp = scaling(x, x, x);
	w->objects->t = matrix_multi(tmp, t, 4, 4);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
	clear_matrix(t, 4);
	clear_matrix(tmp, 4);
}
