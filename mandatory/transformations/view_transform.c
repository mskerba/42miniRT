/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:54:43 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 16:39:13 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	clear(t_camera *c)
{
	if (c->transf)
	{
		clear_matrix(c->transf, 4);
		clear_matrix(c->inv, 4);
	}
}

void	view_transform(t_camera *c, t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple	forward;
	t_tuple	left;
	t_tuple	true_up;
	double	**orint;
	double	**tr;

	forward = substract_tuples(to, from);
	normalize_tuple(&forward);
	left = cross_product(forward, up);
	normalize_tuple(&left);
	true_up = cross_product(left, forward);
	normalize_tuple(&true_up);
	orint = scaling(left.x, true_up.y, -forward.z);
	orint[0][1] = left.y;
	orint[0][2] = left.z;
	orint[1][0] = true_up.x;
	orint[1][2] = true_up.z;
	orint[2][0] = -forward.x;
	orint[2][1] = -forward.y;
	tr = translation(-from.x, -from.y, -from.z);
	clear(c);
	c->transf = matrix_multi(orint, tr);
	c->inv = inverse_matrix(c->transf);
}
