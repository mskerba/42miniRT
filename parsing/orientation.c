/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:56:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 10:56:55 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**orientation(char *s, int len)
{
	double	a;
	double	**r;

    a = get_value(s, ',', len) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = rotation_x(a);
	a = get_value(s, ',', len) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = matrix_multi(rotation_y(a), r);
	a = get_value(s, ' ', len) * M_PI;
	if (a < 0)
		a = (2 * M_PI) + a;
	r = matrix_multi(rotation_z(a), r);
    return (r);
}
