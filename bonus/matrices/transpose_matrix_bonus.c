/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:35 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

double	**transpose_matrix(double **m, int size)
{
	double	**transpose;
	int		i;
	int		j;

	transpose = create_matrix(size, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			transpose[i][j] = m[j][i];
	}
	return (transpose);
}
