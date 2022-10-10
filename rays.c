/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:04:51 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 21:33:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

t_ray	*create_ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_tuple	*position(t_ray *ray, double t)
{
	t_tuple	*pos;
	t_tuple	*tmp;

	tmp = scalar_multi(ray->direction, t);
	if (!tmp)
		return (NULL);
	pos = add_tuples(ray->origin, tmp);
	free(tmp);
	return (pos);
}


