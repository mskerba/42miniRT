/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:54:21 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 09:54:44 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	get_value(char *s, char c, int len)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (i >= len)
	{
		write(2, "component not fount\n", 21);
		exit (1);
	}
	while (s[i] && s[i] == ' ')
		i++;
	if (i >= len)
	{
		write(2, "component not fount\n", 21);
		exit (1);
	}
	j = i;
	while (s[i] && s[i] != c && s[i] != ' ')
		i++;
	s[i++] = 0;
	return (d_atoi(s + j));
}
