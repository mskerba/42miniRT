/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 15:12:18 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_cylindre(t_world *w, char *s, int len)
{
    double	x;
	double	y;
	double	z;
    double  **t;
    double  **tmp;

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
    x = get_value(s, ' ', len) / 2.0;
    tmp = scaling(x, 1.0, x);
    w->objects->t = matrix_multi(tmp, t, 4, 4);
    w->objects->inv = inverse_matrix(w->objects->t);
    w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	
    x = get_value(s, ' ', len);
	w->objects->cyl_min = 0;
	w->objects->cyl_max = x;
	
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
    clear_matrix(t, 4);
    clear_matrix(tmp, 4);
	display_matrix(w->objects->t, 4, 4);
}