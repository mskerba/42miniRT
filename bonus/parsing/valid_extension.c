/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:23:47 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/03 11:33:26 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	valid_extension(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i < 4 || !(s[i - 3] == '.' && s[i - 2] == 'r' && s[i - 1] == 't'))
		error(NULL, "invalid extension\n");
}
