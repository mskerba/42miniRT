/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:30:10 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/31 16:55:12 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

int valid_map(int ac, char *s)
{
    int	fd;

	if (ac > 2)
	;
		// error("too many arguments!");
	// if (ac < 2)
		// error("missing map!");
	// valid_extension(s);
	fd = open(s, O_RDONLY);
	// if (fd < 0)
		// error("The map cannot be opened!");
	return (fd);
}