/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_matrix_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:01:13 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

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
