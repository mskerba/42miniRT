/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:04 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 15:12:26 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_sphere(t_world *w, char *s, int len)
{
    double	x;
	double	y;
	double	z;
    double  **t;
    double  **tmp;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	t = translation(x, y, z);
	add_object(&w->objects, 's', t);
    x = get_value(s, ' ', len) / 2.0;
    tmp = scaling(x, x, x);
    w->objects->t = matrix_multi(tmp, t, 4, 4);
    w->objects->inv = inverse_matrix(w->objects->t);
    w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
    clear_matrix(t, 4);
    clear_matrix(tmp, 4);
}