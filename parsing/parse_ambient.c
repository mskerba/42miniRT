/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:59:15 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 10:00:07 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parse_ambient(t_comp *comps, char *s, int len)
{
	double	x;
	double	y;
	double	z;

	comps->ambient.ambient = get_value(s, ' ', len);
	x = get_value(s, ',', len);
	y = get_value(s, ',', len);
	z = get_value(s, '\n', len);
	comps->ambient.color = create_tuple(x, y, z, 1);
}
