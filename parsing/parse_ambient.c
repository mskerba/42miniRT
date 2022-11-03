/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:59:15 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 12:54:06 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_ambient(t_world *w, char *s, int len)
{
	double	range[2];

	range[0] = -1.0;
	range[1] = 1.0;
	w->ambient.ambient = set_value(s, ' ', len, range);
	w->ambient.color = parse_color(s, len, '\n');
}
