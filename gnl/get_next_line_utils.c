/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:13:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/30 11:22:25 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_buf(char *buff)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (1);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	len(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_calloc(char *buffer, size_t count, size_t size)
{
	size_t	i;

	i = 0;
	if (buffer)
		return (buffer);
	buffer = (char *)malloc(count * size);
	if (!buffer)
		return (NULL);
	while (i < (count * size))
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}
