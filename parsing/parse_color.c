/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:43:24 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 09:12:44 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

t_tuple parse_color(char *s, int len, char c)
{
    double  r;
    double  g;
    double  b;
    t_tuple color;

    r = get_value(s, ',', len) / 255.0;
	g = get_value(s, ',', len) / 255.0;
	b = get_value(s, c, len) / 255.0;
    color = create_tuple(r, g, b, 1);
    return (color);
}