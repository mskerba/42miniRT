/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:03:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 08:48:03 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_value(int fd, char c)
{
	char	token[1000];
    int i;

    i = 0;
    while (1)
    {
        if (read(fd, token, 1) <= 0)
            break ;
        if (token[0] != ' ' && token[0] != '\n')
            break ;
    }
    while (token[i] != c && token[i] != ' ')
    {
        i++;
        if (read(fd, token + i, 1) <= 0)
            break ;
    }
	token[i] = 0;
    return (d_atoi(token));
}

void    parse_ambient(t_world *world, int fd)
{
    (void) world;
	get_value(fd, ' ');
	get_value(fd, ',');
	get_value(fd, ',');
	get_value(fd, '\n');
}