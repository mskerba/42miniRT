/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:27:54 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 21:28:23 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	normal_at(t_object *obj, t_tuple *w_point)
{
	t_tuple	o_point;
	t_tuple	o_normal;
	t_tuple	w_normal;
	
	o_point = matrix_x_tuple(obj->inv, *w_point);
	o_normal = create_tuple(o_point.x, o_point.y, o_point.z, 0);
	w_normal = matrix_x_tuple(obj->transp, o_normal);
	w_normal.w = 0;
	normalize_tuple(&w_normal);
	return (w_normal);
}
