/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:11:38 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 15:43:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_world	parser(t_world *world, t_comp *comp, t_camera *c, int fd)
{
	char	*line;
	char	*token;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		*c = *c;
		// len = ft_strlen(line);
		token = get_token(line);
		len = ft_strlen(token);
		if (!ft_strcmp(token, "A"))
			parse_ambient(comp, line + len + 1, ft_strlen(line + len + 1));
		// else if (!ft_strcmp(token, "C"))
		// parse_camera(*c, line + len + 1);
		// else if (!ft_strcmp(token, "L"))
		// world->light = parse_light(line + len + 1);
		else if (!ft_strcmp(token, "sp"))
			parse_sphere(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "cy"))
			parse_cylindre(world, line + len + 1, ft_strlen(line + len + 1));
		else if (!ft_strcmp(token, "pl"))
			parse_plan(world, line + len + 1, ft_strlen(line + len + 1));
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	return (*world);
}
