/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:30:56 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/02 09:31:22 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**coordinate(char *s, int len)
{
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	return (translation(x, y, z));
}
