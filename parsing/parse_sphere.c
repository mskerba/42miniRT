/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:04 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 12:00:37 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_sphere(t_world *w, int fd)
{
    double	x;
	double	y;
	double	z;
    // double  **tmp;
    // double  **tmp1;

	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	add_object(&w->objects, 's', translation(x, y, z));
    x = get_value(fd, ' ') / 2.0;
    // tmp1 = scaling(x, x, x);
    // tmp = matrix_multi(w->objects->t, tmp1, 4, 4);
    // clear_matrix(tmp1, 4);
    // clear_matrix(w->objects->t, 4);
    // w->objects->t = tmp;
    w->objects->inv = inverse_matrix(w->objects->t);
    w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);

	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.ambient = 0.1;
	w->objects->m.diffuse = get_value(fd, ' ');
	w->objects->m.specular = get_value(fd, ' ');
	w->objects->m.shininess = get_value(fd, '\n');
}