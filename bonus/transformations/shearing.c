/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskerba <mskerba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:41:26 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/26 18:41:58 by mskerba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	**shearing(int x, int y, int z)
{
	double	**matrix;

	matrix = create_matrix(4, 4);
	matrix[0][0] = 1;
	matrix[0][1] = (double)(x / 10);
	matrix[0][2] = (double)(x % 10);
	matrix[0][3] = 0;
	matrix[1][0] = (double)(y / 10);
	matrix[1][1] = 1;
	matrix[1][2] = (double)(y % 10);
	matrix[1][3] = 0;
	matrix[2][0] = (double)(z / 10);
	matrix[2][1] = (double)(z % 10);
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
	return (matrix);
}
