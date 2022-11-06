/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:56:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 17:44:01 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_tuple	orientation_vec(char *s, int len)
{
	double	a;
	double	range[2];
	t_tuple	orient;

	range[0] = -1.0;
	range[1] = 1.0;
	a = set_value(s, ',', len, range);
	orient.x = a;
	a = set_value(s, ',', len, range);
	orient.y = a;
	a = set_value(s, ' ', len, range);
	orient.z = a;
	orient.w = 0.0;
	a = magnitude(orient);
	if (a > 1.01 || a < 0.90)
		error(NULL, "orientation vector is not normalized!\n");
	return (orient);
}

double	**orient_shape(char *s, int len, bool *is_y_neg)
{
	double	**r;
	t_tuple	orient;

	*is_y_neg = false;
	orient = orientation_vec(s, len);
	orient.x *= M_PI / -2.0;
	orient.z *= M_PI / -2.0;
	if (orient.x < 0)
		orient.x = (2 * M_PI) + orient.x;
	if (orient.z < 0)
		orient.z = (2 * M_PI) + orient.z;
	r = rotation_x(orient.z);
	r = matrix_multi(rotation_z(orient.x), r);
	if (orient.y < 0)
		*is_y_neg = true;
	return (r);
}
