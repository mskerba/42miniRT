/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:56:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 13:24:36 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**orientation(char *s, int len)
{
	double	a;
	double	**r;
	double	range[2];

	range[0] = -1.0;
	range[1] = 1.0;
	a = set_value(s, ',', len, range) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = rotation_x(a);
	a = set_value(s, ',', len, range) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = matrix_multi(rotation_y(a), r);
	a = set_value(s, ' ', len, range) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = matrix_multi(rotation_z(a), r);
	return (r);
}
