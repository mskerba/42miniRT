/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:49:23 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/28 21:24:27 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	color_at(t_world *world, t_ray *r)
{
	t_comp		comps;
	t_intersect	*intersecs;
	t_tuple		shading;
	int			color;

	color = 0;
	intersecs = intersect_world(world, r);
	if (!hit(intersecs))
		intersecs = intersect_cylindre(world, r);
	if (!hit(intersecs))
		intersecs = local_intersect(world, r);
	if (hit(intersecs))
	{
		comps = prepare_computations(intersecs, r);
		shading = shade_hit(world, &comps);
		color = get_color(shading);
	}
	if (intersecs)
		clear_intersecs(&intersecs);
	return (color);
}
