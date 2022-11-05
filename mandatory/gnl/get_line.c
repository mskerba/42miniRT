/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:08:47 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 23:07:46 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_strcpy(char	*dst, char	*src, char c)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		free(src);
	}
	dst[i++] = c;
	dst[i] = 0;
}

char	*ft_strjoin(char c, char *str)
{
	char	*line;

	line = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!line)
	{
		free(str);
		write(2, "ERROR!\n", 7);
		return (0);
	}
	ft_strcpy(line, str, c);
	return (line);
}

char	*get_line(int fd)
{
	char	c;
	char	*line;

	c = 0;
	line = NULL;
	while (c != '\n' && read(fd, &c, 1) > 0)
		line = ft_strjoin(c, line);
	return (line);
}
