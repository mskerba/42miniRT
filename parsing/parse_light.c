/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:04:01 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 15:23:32 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_light    *parse_light(char *s)
{
    double  x;
    double  y;
    double  z;
    t_light *l;

    l = malloc(sizeof(t_light));
    x = get_value(s, ',');
    y = get_value(s, ',');
    z = get_value(s, ' ');
    l->position = create_tuple(x, y, z, 1);
    get_value(s, ' ');
    x = get_value(s, ',');
    y = get_value(s, ',');
    z = get_value(s, 0);
    l->intensity = create_tuple(x, y, z, 1);
    return (l);
}