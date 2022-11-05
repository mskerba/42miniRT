/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multply_tuple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:35:14 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/29 11:48:51 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	multiply_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple	t;

	t.x = a->x * b->x;
	t.y = a->y * b->y;
	t.z = a->z * b->z;
	t.w = a->w * b->w;
	return (t);
}
