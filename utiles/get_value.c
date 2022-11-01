/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:54:21 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 22:55:46 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_value(char *s, char c, int len)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (i >= len)
		error("component not fount!");
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (i >= len)
		error("component not fount!");
	j = i;
	while (s[i] && s[i] != c && (s[i] != ' ' || s[i] == '\t'))
		i++;
	s[i++] = 0;
	if (c == '\n')
		i = 0;
	return (d_atoi(s + j));
}
