/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:01 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 13:24:55 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_light(t_world	*w, char *s, int len)
{
	double	x;
	double	y;
	double	z;
	double	range[2];

	range[0] = 0.0;
	range[1] = 1.0;
	x = set_value(s, ',', len, NULL);
	y = set_value(s, ',', len, NULL);
	z = set_value(s, ' ', len, NULL);
	w->light->position = create_tuple(x, y, z, 1);
	w->diffuse = set_value(s, ' ', len, range);
	w->light->intensity = parse_color(s, len, '\n');
}
