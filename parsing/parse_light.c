/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:01 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 08:48:11 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_light    *parse_light(int fd)
{
    double  x;
    double  y;
    double  z;
    t_light *l;

    l = malloc(sizeof(t_light));
    x = get_value(fd, ',');
    y = get_value(fd, ',');
    z = get_value(fd, ' ');
    l->position = create_tuple(x, y, z, 1);
    get_value(fd, ' ');
    x = get_value(fd, ',');
    y = get_value(fd, ',');
    z = get_value(fd, '\n');
    l->intensity = create_tuple(x, y, z, 1);
    return (l);
}