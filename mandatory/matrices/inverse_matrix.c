/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:37 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 08:50:11 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**inverse_matrix(double **m)
{
	double	**inverse;
	double	**cof;
	double	det;
	int		i;
	int		j;

	cof = cofactor(m);
	det = determinant(m, cof);
	if (!det)
	{
		clear_matrix(cof, 4);
		return (NULL);
	}
	inverse = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			inverse[j][i] = cof[i][j] / det;
	}
	clear_matrix(cof, 4);
	return (trim_matrix(inverse));
}
