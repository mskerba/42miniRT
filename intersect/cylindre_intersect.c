/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:46:09 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/29 10:46:10 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../miniRT.h"

void	cylindre_inter(t_object *cylindre, t_ray *r, t_intersect **inter)
{
	t_ray	r1;
	double	*t;
	
	r1.origin = matrix_x_tuple(cylindre->inv, r->origin);
	r1.direction = matrix_x_tuple(cylindre->inv, r->direction);
	normalize_tuple(&r1.direction);
	t = inter_cyl(r1);
	if (t)
	{
		intersections(inter, cylindre, t[0]);
		if (!compare(t[0], t[1]))
			intersections(inter, cylindre, t[1]);
		free(t);
	}
}
