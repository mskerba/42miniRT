/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:41 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 19:06:17 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	cof(double **sub_m, int i, int j)
{
	double	cofact;

	cofact = sub_m[0][0] * ((sub_m[1][1] * sub_m[2][2]) \
	- ((sub_m[2][1] * sub_m[1][2])));
	cofact -= sub_m[0][1] * ((sub_m[1][0] * sub_m[2][2]) \
	- (sub_m[2][0] * sub_m[1][2]));
	cofact += sub_m[0][2] * ((sub_m[1][0] * sub_m[2][1]) \
	- (sub_m[2][0] * sub_m[1][1]));
	if ((i + j) % 2)
		return (-cofact);
	return (cofact);
}

double	**cofactor(double **m)
{
	double	**sub_m;
	double	**cofactors;
	int		i;
	int		j;

	cofactors = create_matrix(4, 4);
	sub_m = create_matrix(3, 3);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			get_submatrix(m, sub_m, i, j);
			cofactors[i][j] = cof(sub_m, i, j);
		}
	}
	clear_matrix(sub_m, 3);
	return (cofactors);
}
