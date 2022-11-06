/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:30:10 by momeaizi          #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

int	valid_map(int ac, char *s)
{
	int	fd;

	if (ac > 2)
		error(NULL, "too many arguments!\n");
	if (ac < 2)
		error(NULL, "missing map!\n");
	valid_extension(s);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		error(NULL, "The map cannot be opened!\n");
	return (fd);
}
