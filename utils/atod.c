/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:21:25 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 13:13:52 by momeaizi         ###   ########.fr       */
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
		return (atod(s) * sign);
	else if (s[0] == '.')
		return (atod(s + i + 1) / pow(10, ft_strlen(s + i + 1)) * sign);
	s[i] = 0;
	result = atod(s);
	result += (atod(s + i + 1) / pow(10, ft_strlen(s + i + 1)));
	return (result * sign);
}
