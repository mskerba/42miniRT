/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:56:11 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:58:48 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**matrix_multi(double **a, double **b, int rows, int columns)
{
	double	**m;
	int		i;
	int		j;

	m = create_matrix(rows, columns);
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < columns)
		{
			m[i][j] = (a[i][0] * b[0][j]) + \
			(a[i][1] * b[1][j]) + \
			(a[i][2] * b[2][j]) + \
			(a[i][3] * b[3][j]);
		}
	}
	return (m);
}
