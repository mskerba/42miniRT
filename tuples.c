/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:50:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/19 08:59:00 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_tuple(t_tuple *t)
{
	printf("(%lf, %lf, %lf, %lf)\n", t->x, t->y, t->z, t->w);
}

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple.x = a.x + b.x;
	tuple.y = a.y + b.y;
	tuple.z = a.z + b.z;
	tuple.w = a.w + b.w;
	return (tuple);
}

t_tuple	substract_tuples(t_tuple a, t_tuple b)
{
	t_tuple	tuple;

	tuple.x = a.x - b.x;
	tuple.y = a.y - b.y;
	tuple.z = a.z - b.z;
	tuple.w = a.w - b.w;
	return (tuple);
}

t_tuple	negate_tuple(t_tuple tpl)
{
	t_tuple	tuple;

	tuple.x = -tpl.x;
	tuple.y = -tpl.y;
	tuple.z = -tpl.z;
	tuple.w = -tpl.w;
	return (tuple);
}

t_tuple	scalar_multi(t_tuple tpl, double scalar)
{
	t_tuple	tuple;

	tuple.x = scalar * tpl.x;
	tuple.y = scalar * tpl.y;
	tuple.z = scalar * tpl.z;
	tuple.w = scalar * tpl.w;
	return (tuple);
}

double	magnitude(t_tuple tuple)
{
	return (sqrt(pow(tuple.x, 2) \
	+ pow(tuple.y, 2) \
	+ pow(tuple.z, 2) \
	+ pow(tuple.w, 2)));
}

void	normalize_tuple(t_tuple *tuple)
{
	double	magn;

	magn = magnitude(*tuple);
	tuple->x /= magn;
	tuple->y /= magn;
	tuple->z /= magn;
	tuple->w /= magn;
}

double	dot_product(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) \
	+ (a.y * b.y) \
	+ (a.z * b.z) \
	+ (a.w * b.w));
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	return (
		create_tuple((a.y * b.z) - (a.z * b.y), \
		(a.z * b.x) - (a.x * b.z), \
		(a.x * b.y) - (a.y * b.x), \
		0)
	);
}
