/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:00:52 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/22 11:21:54 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	**translation(double x, double y, double z)
{
	double	**matrix;

	matrix = scaling(1, 1, 1);
	matrix[0][3] = x;
	matrix[1][3] = y;
	matrix[2][3] = z;
	return (matrix);
}

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

double	**scaling(double x, double y, double z)
{
	double	**matrix;
	int		i;
	int		j;

	matrix = create_matrix(4, 4);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			matrix[i][j] = 0;
	}
	matrix[0][0] = x;
	matrix[1][1] = y;
	matrix[2][2] = z;
	matrix[3][3] = 1;
	return (matrix);
}

//x_y = x / 10 && x_z = x % 10
//y_x = y / 10 && y_z = y % 10
//z_x = z / 10 && z_y = z % 10
/*old prototype : double	**shearing(double x_y, double x_z,
	double y_x, double y_z, double z_x, double z_y);*/

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
