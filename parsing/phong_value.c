/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:27:21 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 12:53:15 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	phong_value(t_world *w, char *s, int len)
{
	double	range[2];

	range[0] = -1.0;
	range[1] = 1.0;
	w->objects->m.color = parse_color(s, len, ' ');
	w->objects->m.specular = set_value(s, ' ', len, range);
	range[0] = 10.0;
	range[1] = 200.0;
	w->objects->m.shininess = set_value(s, '\n', len, range);
}
