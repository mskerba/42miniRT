/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:11:38 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/04 18:25:53 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	parser(t_world *world, t_camera *c, char *line, int fd)
{
	char	*token;
	int		len;

	while (line)
	{
		token = get_token(line, ' ', ft_strlen(line));
		len = ft_strlen(token);
		if (!ft_strcmp(token, "A"))
			parse_ambient(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "C"))
			parse_camera(c, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "L"))
			parse_light(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "sp"))
			parse_sphere(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "cy"))
			parse_cylinder(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "pl"))
			parse_plan(world, line + len + 1, ft_strlen(line + len + 1));
		else
			error(token, "invalid identifier!\n");
		free(line);
		line = get_line(fd);
	}
}
