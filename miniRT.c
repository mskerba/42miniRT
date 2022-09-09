/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:44 by momeaizi          #+#    #+#             */
/*   Updated: 2022/09/03 11:03:39 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	*create_tuple(double x, double y, double z, double w)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (tuple);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}

bool	compare(double a, double b)
{
	if (abs(a - b) < EPSILON)
		return (true);
	return (false);
}