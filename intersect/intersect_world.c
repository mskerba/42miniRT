/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:59:20 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 20:12:41 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_intersect	*intersect_world(t_world *world, t_ray *r)
{
	t_intersect	*inter;
	t_object	*obj;
	double		*t;
	t_ray		r1;

	inter = NULL;
	obj = world->objects;
	while (obj)
	{
		if (obj->type == 's')
		{
			r1.origin = matrix_x_tuple(obj->inv, r->origin);
			r1.direction = matrix_x_tuple(obj->inv, r->direction);
			normalize_tuple(&r1.direction);
			t = intersect(r1);
			if (t)
			{
				intersections(&inter, obj, t[0]);
				if (!compare(t[0], t[1]))
					intersections(&inter, obj, t[1]);
				free(t);
			}
		}
		obj = obj->next;
	}
	return (inter);
}
