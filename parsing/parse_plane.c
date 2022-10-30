/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 11:36:31 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_plan(t_world *w, int fd)
{
	double	x;
	double	y;
	double	z;

	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	add_object(&w->objects, 'p', translation(x, y, z));
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);

	//orient
	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	//color
	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.ambient = 0.001;
	w->objects->m.diffuse = get_value(fd, ' ');
	w->objects->m.specular = get_value(fd, ' ');
	w->objects->m.shininess = get_value(fd, '\n');
}