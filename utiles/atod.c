/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:21:25 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/02 14:14:36 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	atod(char *s)
{
	double	result;
	int		i;

	i = -1;
	result = 0;
	if (s[0] == '-')
		i = 0;
	while (s[++i])
		result = (result * 10) + (s[i] - '0');
	return (result);
}

double	d_atoi(char *s)
{
	double	result;
	int		i;
	double	sign;

	i = -1;
	sign = 1.0;
	if (s[0] == '-')
		sign = -1.0;
	while (s[++i] && s[i] != '.')
		;
	if (s[i] != '.')
		return (atod(s));
	s[i] = 0;
	result = atod(s);
	result += (atod(s + i + 1) / pow(10, ft_strlen(s + i + 1)));
	return (result * sign);
}
