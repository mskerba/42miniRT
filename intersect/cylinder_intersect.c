/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:46:09 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/04 18:25:53 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	check_cap(t_ray *r,	double t)
{
	double	x;
	double	z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return (pow(x, 2) + pow(z, 2));
}

void	cylinder_inter(t_object *cylinder, t_ray *r, t_intersect **inter)
{
	t_ray	r1;
	double	*t;
	double	y;

	r1.origin = matrix_x_tuple(cylinder->inv, r->origin);
	r1.direction = matrix_x_tuple(cylinder->inv, r->direction);
	normalize_tuple(&r1.direction);
	t = inter_cyl(r1, cylinder->radius);
	if (t)
	{
		y = r1.origin.y + t[0] * r1.direction.y;
		if (cylinder->cyl_min < y && y < cylinder->cyl_max)
			intersections(inter, cylinder, t[0]);
		y = r1.origin.y + t[1] * r1.direction.y;
		if (!compare(t[0], t[1]) && \
		cylinder->cyl_min < y && y < cylinder->cyl_max)
			intersections(inter, cylinder, t[1]);
		free(t);
	}
	y = (cylinder->cyl_min - r1.origin.y) / r1.direction.y;
	if (check_cap(&r1, y) <= cylinder->radius)
		intersections(inter, cylinder, y);
	y = (cylinder->cyl_max - r1.origin.y) / r1.direction.y;
	if (check_cap(&r1, y) <= cylinder->radius)
		intersections(inter, cylinder, y);
}
