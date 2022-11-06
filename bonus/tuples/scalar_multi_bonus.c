/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_multi_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:26:46 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	scalar_multi(t_tuple tpl, double scalar)
{
	t_tuple	tuple;

	tuple.x = scalar * tpl.x;
	tuple.y = scalar * tpl.y;
	tuple.z = scalar * tpl.z;
	tuple.w = scalar * tpl.w;
	return (tuple);
}
