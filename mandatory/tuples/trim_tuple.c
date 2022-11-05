/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_tuple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:44:45 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 19:45:06 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	trim_tuple(t_tuple *tuple)
{
	if (tuple->x < EPSILON && tuple->x > -EPSILON)
		tuple->x = 0.0;
	if (tuple->y < EPSILON && tuple->y > -EPSILON)
		tuple->y = 0.0;
	if (tuple->z < EPSILON && tuple->z > -EPSILON)
		tuple->z = 0.0;
	if (tuple->w < EPSILON && tuple->w > -EPSILON)
		tuple->w = 0.0;
}
