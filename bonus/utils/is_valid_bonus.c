/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:12:14 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:21 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	is_valid(char *token)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	if (token[0] == '-')
		i = 0;
	while (token[++i])
	{
		if (token[i] == '.')
			count++;
		else if (!is_digit(token[i]))
			error(NULL, "Invalid value!\n");
		if (count > 1)
			error(NULL, "Too many \'.\' !\n");
	}
}
