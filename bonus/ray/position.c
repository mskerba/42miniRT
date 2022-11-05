/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:47:30 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:48:08 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;

	pos = scalar_multi(ray.direction, t);
	pos = add_tuples(ray.origin, pos);
	return (pos);
}
