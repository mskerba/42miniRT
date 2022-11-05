/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:06 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:36 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	normalize_tuple(t_tuple *tuple)
{
	double	magn;

	magn = magnitude(*tuple);
	tuple->x /= magn;
	tuple->y /= magn;
	tuple->z /= magn;
	tuple->w /= magn;
}
