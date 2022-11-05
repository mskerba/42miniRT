/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:26:46 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:39 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	scalar_multi(t_tuple tpl, double scalar)
{
	t_tuple	tuple;

	tuple.x = scalar * tpl.x;
	tuple.y = scalar * tpl.y;
	tuple.z = scalar * tpl.z;
	tuple.w = scalar * tpl.w;
	return (tuple);
}
