/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:18 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/06 18:10:24 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

double	**rotation_x(double r)
{
	double	**matrix;

	matrix = create_matrix(4, 4);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(r);
	matrix[1][2] = -sin(r);
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = sin(r);
	matrix[2][2] = cos(r);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
	return (matrix);
}

double	**rotation_y(double r)
{
	double	**matrix;

	matrix = create_matrix(4, 4);
	matrix[0][0] = cos(r);
	matrix[0][1] = 0;
	matrix[0][2] = sin(r);
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = -sin(r);
	matrix[2][1] = 0;
	matrix[2][2] = cos(r);
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
	return (matrix);
}

double	**rotation_z(double r)
{
	double	**matrix;

	matrix = create_matrix(4, 4);
	matrix[0][0] = cos(r);
	matrix[0][1] = -sin(r);
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = sin(r);
	matrix[1][1] = cos(r);
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
	return (matrix);
}
