/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate_tuple_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:25:49 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	negate_tuple(t_tuple tpl)
{
	t_tuple	tuple;

	tuple.x = -tpl.x;
	tuple.y = -tpl.y;
	tuple.z = -tpl.z;
	tuple.w = -tpl.w;
	return (tuple);
}
