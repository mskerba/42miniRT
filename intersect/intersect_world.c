/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:59:20 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/29 10:54:25 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_intersect	*intersect_world(t_world *world, t_ray *r)
{
	t_intersect	*inter;
	t_object	*obj;

	inter = NULL;
	obj = world->objects;
	while (obj)
	{
		if (obj->type == 's')
			sphere_inter(obj, r, &inter);
		else if (obj->type == 'c')
			cylindre_inter(obj, r, &inter);
		else if (obj->type == 'p')
			plane_inter(obj, r, &inter);
		obj = obj->next;
	}
	return (inter);
}
