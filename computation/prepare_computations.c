/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:40:43 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/28 21:06:29 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_comp	prepare_computations(t_intersect *intersecs, t_ray *r)
{
	t_comp	comps;

	comps.t = intersecs->t;
	comps.obj = intersecs->object;
	comps.point = position(*r, comps.t);
	comps.eyev = negate_tuple(r->direction);
	if (comps.obj->type == 'c')
		comps.normalv = cyl_normal_at(comps.obj, &comps.point);
	else if (comps.obj->type == 's')
		comps.normalv = normal_at(comps.obj, &comps.point);
	else
		comps.normalv = local_normal_at(comps.obj, &comps.point);
	comps.over_point = add_tuples(comps.point, scalar_multi(comps.normalv, EPSILON));
	if (compare(dot_product(comps.normalv, comps.eyev), 0))
	{
		comps.inside = true;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = false;
	trim_tuple(&comps.normalv);
	trim_tuple(&comps.eyev);
	return (comps);
}
