/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:40:46 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

double	**scaling(double x, double y, double z)
{
	double	**matrix;
	int		i;
	int		j;

	matrix = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			matrix[i][j] = 0;
	}
	matrix[0][0] = x;
	matrix[1][1] = y;
	matrix[2][2] = z;
	matrix[3][3] = 1;
	return (matrix);
}
