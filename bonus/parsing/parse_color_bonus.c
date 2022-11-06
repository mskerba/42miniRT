/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:43:24 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_tuple	parse_color(char *s, int len, char c)
{
	double	r;
	double	g;
	double	b;
	t_tuple	color;
	double	range[2];

	range[0] = 0.0;
	range[1] = 255.0;
	r = set_value(s, ',', len, range) / 255.0;
	g = set_value(s, ',', len, range) / 255.0;
	b = set_value(s, c, len, range) / 255.0;
	color = create_tuple(r, g, b, 1);
	return (color);
}
