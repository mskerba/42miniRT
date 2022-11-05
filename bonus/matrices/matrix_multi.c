/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:56:11 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 10:57:19 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**matrix_multi(double **a, double **b)
{
	double	**m;
	int		i;
	int		j;

	m = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			m[i][j] = (a[i][0] * b[0][j]) + \
			(a[i][1] * b[1][j]) + \
			(a[i][2] * b[2][j]) + \
			(a[i][3] * b[3][j]);
		}
	}
	clear_matrix(a, 4);
	clear_matrix(b, 4);
	return (m);
}
