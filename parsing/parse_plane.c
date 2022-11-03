/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 10:56:41 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

//first scale, then rotate, then translate

void	parse_plan(t_world *w, char *s, int len)
{
	double	**t;

	t = coordinates(s, len);
	t = matrix_multi(t, orientation(s, len));
	add_object(&w->objects, 'p', t);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
}
