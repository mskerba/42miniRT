/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:17:47 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

double	set_value(char *s, char c, int len, double *range)
{
	char	*token;
	double	n;

	token = get_token(s, c, len);
	is_valid(token);
	n = d_atoi(token);
	if (range && (n < range[0] || n > range[1]))
		error(NULL, "value out of the expected range!\n");
	return (n);
}
