/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:58:49 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 12:45:57 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**coordinates(char *s, int len)
{
	double	x;
	double	y;
	double	z;

	x = set_value(s, ',', len, NULL);
	y = set_value(s, ',', len, NULL);
	z = set_value(s, ' ', len, NULL);
	return (translation(x, y, z));
}
