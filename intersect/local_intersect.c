/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:00:27 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 20:11:12 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_intersect	*local_intersect(t_world *world, t_ray *r)
{
	t_intersect	*inter;
	t_object	*obj;
	double		t;
	t_ray		r1;

	inter = NULL;
	obj = world->objects;
	while (obj)
	{
		if (obj->type == 'p')
		{
			if (fabs(r->direction.y) < EPSILON)
				return (NULL);
			r1.origin = matrix_x_tuple(obj->inv, r->origin);
			r1.direction = matrix_x_tuple(obj->inv, r->direction);
			normalize_tuple(&r1.direction);
			t = -r1.origin.y / r1.direction.y;
			if (t)
				intersections(&inter, obj, t);
		}
		obj = obj->next;
	}
	return (inter);
}
