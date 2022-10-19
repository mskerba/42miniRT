/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:04:51 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/19 09:04:09 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


t_intersect	*hit(t_intersect *head)
{
	return (head);
}

t_ray	create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos = scalar_multi(*ray.direction, t);
	pos = add_tuples(*ray.origin, pos);
	return (pos);
}
