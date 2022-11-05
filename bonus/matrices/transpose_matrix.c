/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:35 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:58:23 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

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
