/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:59:41 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 19:00:03 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_strlcat(char *dst, char *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && start < (len - i))
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[i + start] = 0;
}

char	*ft_strjoin(char *line, char *buff)
{
	size_t	line_len;
	size_t	buff_len;
	char	*str;

	line_len = ft_strlen(line);
	buff_len = ft_strlen(buff);
	if (!buff_len)
		return (NULL);
	str = (char *)malloc((buff_len + line_len + 1) * sizeof(char));
	if (!str)
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (line)
		ft_strlcat(str, line, 0, line_len);
	ft_strlcat(str, buff, line_len, buff_len + line_len);
	if (line)
		free(line);
	return (str);
}

char	*reset_buff(char *buffer)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(buffer);
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (j < i)
		buffer[j++] = 0;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes;

	line = NULL;
	buffer = (char *)ft_calloc(buffer, (BUFFER_SIZE + 1), sizeof(char));
	line = ft_strjoin(line, buffer);
	while (check_buf(buffer))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = 0;
		line = ft_strjoin(line, buffer);
	}
	buffer = reset_buff(buffer);
	if (!len(buffer))
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
