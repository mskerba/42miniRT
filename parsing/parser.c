/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:11:38 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 08:23:29 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_world parser(t_world *world, t_camera *c, int fd)
{
    char    token[3];
    int     i;

    i = -1;
    while (1)
    {
        ++i;
        if (read(fd, token + i, 1) <= 0)
            break;
        if (token[i] != ' ')
            continue ;
        token[i] = 0;
        i = -1;
        if (!ft_strcmp(token, "A"))
            parse_ambient(world, fd);
        else if (!ft_strcmp(token, "C"))
            *c = parse_camera(*c, fd);
        else if (!ft_strcmp(token, "L"))
            world->light = parse_light(fd);
        else if (!ft_strcmp(token, "sp"))
            parse_sphere(world, fd);
        else if (!ft_strcmp(token, "cy"))
            parse_cylindre(world, fd);
        else if (!ft_strcmp(token, "pl"))
            parse_plan(world, fd);
    }
    return (*world);
}