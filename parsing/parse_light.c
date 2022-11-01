/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:01 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 23:02:12 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_light(t_world	*w, char *s, int len)
{
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->light->position = create_tuple(x, y, z, 1);
	w->diffuse = get_value(s, ' ', len);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, '\n', len);
	w->light->intensity = create_tuple(x, y, z, 1);
}
