/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:46:09 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 21:15:32 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_cap(t_ray *r,	double t)
{
	double x;
	double z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return (pow(x, 2) + pow(z, 2));
}

void	cylindre_inter(t_object *cylindre, t_ray *r, t_intersect **inter)
{
	t_ray	r1;
	double	*t;
	double	y;

	r1.origin = matrix_x_tuple(cylindre->inv, r->origin);
	r1.direction = matrix_x_tuple(cylindre->inv, r->direction);
	normalize_tuple(&r1.direction);
	t = inter_cyl(r1);
	if (t)
	{
		y = r->origin.y + t[0] * r->direction.y;
		if (cylindre->cyl_min < y && y < cylindre->cyl_max)
			intersections(inter, cylindre, t[0]);
		// y = r->origin.y + t[1] * r->direction.y;
		// if (!compare(t[0], t[1]) && cylindre->cyl_min < y && y < cylindre->cyl_max)
		// 	intersections(inter, cylindre, t[1]);
		free(t);
	}
	// y = (cylindre->cyl_min - r->origin.y) / r->direction.y;
	// if(check_cap(r, y) <= 1)
	// 	intersections(inter, cylindre, y);
	// y = (cylindre->cyl_max - r->origin.y) / r->direction.y;
	// if(check_cap(r, y) <= 1)
	// 	intersections(inter, cylindre, y);
}
