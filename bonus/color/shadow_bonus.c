/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:05:32 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	is_shadowed(t_world *world, t_tuple point)
{
	t_ray		r;
	t_tuple		v;
	t_intersect	*intersecs;
	double		distance;
	bool		in_shadow;

	in_shadow = false;
	v = substract_tuples(world->light->position, point);
	distance = magnitude(v);
	normalize_tuple(&v);
	r = create_ray(point, v);
	intersecs = intersect_world(world, &r);
	if (hit(intersecs))
		if (intersecs->t < distance)
			in_shadow = true;
	if (intersecs)
		clear_intersecs(&intersecs);
	return (in_shadow);
}
