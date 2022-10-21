/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:04:51 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/21 17:52:02 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


t_intersect	*hit(t_intersect *head)
{
	if (head && head->t >= 0)
		return (head);
	return (NULL);
}

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos = scalar_multi(ray.direction, t);
	pos = add_tuples(ray.origin, pos);
	return (pos);
}
