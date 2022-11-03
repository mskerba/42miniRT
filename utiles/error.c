/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:45:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 11:32:36 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	error(char *s1, char *s2)
{
	if (s1)
	{
		while (*s1)
			write(2, s1++, 1);
		write(2, " : ", 3);
	}
	if (s2)
		while (*s2)
			write(2, s2++, 1);
	exit(24);
}
