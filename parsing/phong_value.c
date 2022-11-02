/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:27:21 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/02 09:30:13 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	phong_value(t_world *w, char *s, int len)
{	
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len) / 255.0;
	y = get_value(s, ',', len) / 255.0;
	z = get_value(s, ' ', len) / 255.0;
	w->objects->m.color = create_tuple(x, y, z, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
}
