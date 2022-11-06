/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_normal_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:05:58 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 16:35:48 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	cyl_normal_at(t_object *obj, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	double	dist;
	double	rad;

	o_point = matrix_x_tuple(obj->inv, *w_point);
	rad = pow(obj->radius, 2.0);
	dist = pow(o_point.x, 2) + pow(o_point.z, 2);
	if (dist < rad && o_point.y >= obj->cyl_max - EPSILON)
		o_normal = create_tuple(0.0, 1.0, 0.0, 0);
	else if (dist < rad && o_point.y <= obj->cyl_min + EPSILON)
		o_normal = create_tuple(0.0, -1.0, 0.0, 0);
	else
		o_normal = create_tuple(o_point.x, 0, o_point.z, 0);
	w_normal = matrix_x_tuple(obj->transp, o_normal);
	w_normal.w = 0;
	normalize_tuple(&w_normal);
	return (w_normal);
}
