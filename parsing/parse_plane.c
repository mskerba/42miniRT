/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 15:12:32 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_plan(t_world *w, char *s, int len)
{
	double	x;
	double	y;
	double	z;
    double  **t;

	//position
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	t = translation(x, y, z);
	add_object(&w->objects, 'c', t);
	//orientation
	x = (get_value(s, ',', len));
	y = (get_value(s, ',', len));
	z = (get_value(s, ' ', len));
	
	t = matrix_multi(rotation_x(x), t, 4, 4);
	t = matrix_multi(rotation_y(y), t, 4, 4);
	t = matrix_multi(rotation_z(y), t, 4, 4);
	//orient();
    w->objects->t = t;
    w->objects->inv = inverse_matrix(w->objects->t);
    w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
	display_matrix(w->objects->t, 4, 4);
}