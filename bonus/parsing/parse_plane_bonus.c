/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

//first scale, then rotate, then translate

void	parse_plan(t_world *w, char *s, int len)
{
	double	**t;
	bool	is_y_neg;

	t = coordinates(s, len);
	t = matrix_multi(t, orient_shape(s, len, &is_y_neg));
	add_object(&w->objects, 'p', t);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
}
