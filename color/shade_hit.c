/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:52:47 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/29 11:46:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	shade_hit(t_world *world, t_comp *comps)
{
	bool	shadowed;

	shadowed = is_shadowed(world, comps->over_point);
	return (lighting(comps, world->light, shadowed));
}
