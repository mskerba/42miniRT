/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_normal_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:05:58 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 08:02:33 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	cyl_normal_at(t_object *obj, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	double	dist;

	o_point = matrix_x_tuple(obj->inv, *w_point);
	dist = pow(o_point.x, 2) + pow(o_point.z, 2);
	if (dist < 1 && o_point.y >= obj->cyl_max - EPSILON)
		o_normal = create_tuple(0.0, 1.0, 0.0, 0);
	else if (dist < 1 && o_point.y <= obj->cyl_min + EPSILON)
		o_normal = create_tuple(0.0, -1.0, 0.0, 0);
	else
		o_normal = create_tuple(o_point.x, 0, o_point.z, 0);
	w_normal = matrix_x_tuple(obj->transp, o_normal);
	w_normal.w = 0;
	normalize_tuple(&w_normal);
	return (w_normal);
}
