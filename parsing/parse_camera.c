/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:59 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 08:48:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_camera    parse_camera(t_camera c, int fd)
{
    double	x;
	double	y;
	double	z;
    t_tuple to;
    t_tuple up;

	x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
    to = create_tuple(x, y, z, 1);

    x = get_value(fd, ',');
	y = get_value(fd, ',');
	z = get_value(fd, ' ');
    up = create_tuple(x, y, z, 0);
    
    c.field_of_view = get_value(fd, '\n') / 180;
    c.hsize = 1000.0;
	c.vsize = 1000.0;
	pixel_size(&c);
	view_transform(&c, create_tuple(0.0 ,0.0, 0.0, 1), to, up);
	c.inv = inverse_matrix(c.transf);

	return (c);
}