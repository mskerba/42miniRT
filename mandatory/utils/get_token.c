/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:57:46 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 20:36:59 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

char	*get_token(char *s, char c, int len)
{
	static int	i = 0;
	int			j;

	j = 0;
	if (!ft_strcmp(s, "\n"))
		return (s);
	if (i >= len)
		error(NULL, "component not fount!\n");
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] == '\n' || !s[i])
		error(NULL, "component not fount!\n");
	j = i;
	while (s[i] && s[i] != c && s[i] != ' ' && s[i] != '\t')
		i++;
	s[i++] = 0;
	if (c == '\n')
		i = 0;
	return (s + j);
}
