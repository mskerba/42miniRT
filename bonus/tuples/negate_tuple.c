/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negate_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:25:49 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:33 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	negate_tuple(t_tuple tpl)
{
	t_tuple	tuple;

	tuple.x = -tpl.x;
	tuple.y = -tpl.y;
	tuple.z = -tpl.z;
	tuple.w = -tpl.w;
	return (tuple);
}
