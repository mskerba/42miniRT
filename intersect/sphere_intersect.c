/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:50:07 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/04 17:58:56 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	sphere_inter(t_object *sphere, t_ray *r, t_intersect **inter)
{
	t_ray	r1;
	double	*t;

	r1.origin = matrix_x_tuple(sphere->inv, r->origin);
	r1.direction = matrix_x_tuple(sphere->inv, r->direction);
	normalize_tuple(&r1.direction);
	t = intersect(r1, sphere->radius, NULL);
	if (t)
	{
		intersections(inter, sphere, t[0]);
		free(t);
	}
}
