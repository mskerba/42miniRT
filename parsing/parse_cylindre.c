/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylindre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:00 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/01 10:12:34 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	phong_value(t_world *w, char *s, int len)
{	
	double	x;
	double	y;
	double	z;

	x = get_value(s, ' ', len);
	w->objects->cyl_min = 0;
	w->objects->cyl_max = x;
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	w->objects->m.color = create_tuple(x / 255.0, y / 255.0, z / 255.0, 1);
	w->objects->m.specular = get_value(s, ' ', len);
	w->objects->m.shininess = get_value(s, '\n', len);
}

double	**cyl_coordinate(char *s, int len)
{
	double	x;
	double	y;
	double	z;

	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, ' ', len);
	return (translation(x, y, z));
}

void	parse_cylindre(t_world *w, char *s, int len)
{
	double	**t;
	double	**tmp;
	double	x;

	t = cyl_coordinate(s, len);
	add_object(&w->objects, 'c', t);
	x = (get_value(s, ',', len));
	t = matrix_multi(rotation_x(x), t, 4, 4);
	x = (get_value(s, ',', len));
	t = matrix_multi(rotation_y(x), t, 4, 4);
	x = (get_value(s, ' ', len));
	t = matrix_multi(rotation_z(x), t, 4, 4);
	x = get_value(s, ' ', len) / 2.0;
	tmp = scaling(x, 1.0, x);
	w->objects->t = matrix_multi(tmp, t, 4, 4);
	w->objects->inv = inverse_matrix(w->objects->t);
	w->objects->inv = trim_matrix(w->objects->inv);
	w->objects->transp = transpose_matrix(w->objects->inv, 4);
	phong_value(w, s, len);
	clear_matrix(t, 4);
	clear_matrix(tmp, 4);
	display_matrix(w->objects->t, 4, 4);
}
