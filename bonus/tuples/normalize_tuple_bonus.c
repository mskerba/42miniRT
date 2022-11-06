/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tuple_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:06 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:59:40 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

void	normalize_tuple(t_tuple *tuple)
{
	double	magn;

	magn = magnitude(*tuple);
	tuple->x /= magn;
	tuple->y /= magn;
	tuple->z /= magn;
	tuple->w /= magn;
}
