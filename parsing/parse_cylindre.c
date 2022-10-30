/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 11:36:31 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void    parse_cylindre(t_world *w, int fd)
{
    double	x;
	double	y;
	double	z;
    double  **tmp;
    double  **tmp1;

    //position
	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	add_object(&w->objects, 'c', translation(x, y, z));
    //oriontation
    x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	//diametre
    x = get_value(fd, ' ') / 2.0;
    tmp1 = scaling(x, x, x);
    tmp = matrix_multi(w->objects->t, tmp1, 4, 4);
    clear_matrix(tmp1, 4);
    clear_matrix(w->objects->t, 4);
    w->objects->t = tmp;
    w->objects->inv = inverse_matrix(tmp);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);


    //hight
    w->objects->cyl_min = 0;
    w->objects->cyl_max = get_value(fd, ' ');


    //color
	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.ambient = 0.001;
	w->objects->m.diffuse = get_value(fd, '\n');
	
	w->objects->m.specular = get_value(fd, '\n');
	w->objects->m.shininess = get_value(fd, '\n');
}