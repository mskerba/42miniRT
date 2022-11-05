/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:01:13 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 19:00:22 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	display_matrix(double **m, int rows, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		printf("| ");
		while (++j < col)
			printf("%lf ", m[i][j]);
		printf("|\n");
	}
	printf("\n");
}
