/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:56:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/05 19:15:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**orientation(char *s, int len)
{
	double	a;
	double	**r;
	double	range[2];
	t_tuple	orient = create_tuple(0, 0, 0, 0);

	range[0] = -1.0;
	range[1] = 1.0;
	a = set_value(s, ',', len, range);
	orient.x = a;
	a = set_value(s, ',', len, range);
	orient.y = a;
	a = set_value(s, ' ', len, range);
	orient.z = a;
	a = magnitude(orient);
	if (a > 1.01 || a < 0.90)
		error(NULL, "orientation vector is not normalized!\n");
	if (orient.x < 0)
		orient.x = (2 * M_PI) + orient.x;
	if (orient.y < 0)
		orient.y = (2 * M_PI) + orient.y;
	if (orient.z < 0)
		orient.z = (2 * M_PI) + orient.z;
	r = rotation_x(orient.y / 2.0);
	r = matrix_multi(rotation_y(orient.x), r);
	r = matrix_multi(rotation_z(orient.z), r);
	return (r);
}