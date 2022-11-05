/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tuples.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:24:20 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:29:54 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple.x = a.x + b.x;
	tuple.y = a.y + b.y;
	tuple.z = a.z + b.z;
	tuple.w = a.w + b.w;
	return (tuple);
}
