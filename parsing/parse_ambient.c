/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:59:15 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 16:35:49 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_ambient(t_world *w, char *s, int len)
{
	double	x;
	double	y;
	double	z;

	w->ambient.ambient = get_value(s, ' ', len);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, '\n', len);
	w->ambient.color = create_tuple(x, y, z, 1);
}
