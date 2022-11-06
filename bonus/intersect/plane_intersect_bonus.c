/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:44:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

void	plane_inter(t_object *plane, t_ray *r, t_intersect **inter)
{
	t_ray	r1;
	double	t;

	if (fabs(r->direction.y) < EPSILON)
		return ;
	r1.origin = matrix_x_tuple(plane->inv, r->origin);
	r1.direction = matrix_x_tuple(plane->inv, r->direction);
	normalize_tuple(&r1.direction);
	t = -r1.origin.y / r1.direction.y;
	intersections(inter, plane, t);
}
