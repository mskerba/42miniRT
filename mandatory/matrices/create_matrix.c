/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:52 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:59:44 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**create_matrix(int rows, int columns)
{
	double	**matrix;
	int		i;

	matrix = malloc(rows * sizeof(double *));
	i = -1;
	while (++i < rows)
		matrix[i] = malloc(columns * sizeof(double));
	return (matrix);
}
