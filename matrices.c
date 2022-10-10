/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:49:37 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 18:38:30 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

double	**matrix_multi(double **a, double **b, int rows, int columns)
{
	double	**m;
	int	i;
	int	j;

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

t_tuple	*matrix_x_tuple(double **m, t_tuple *t)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (tuple);
	tuple->x = (m[0][0] * t->x) + (m[0][1] * t->y) + (m[0][2] * t->z) + (m[0][3] * t->w);
	tuple->y = (m[1][0] * t->x) + (m[1][1] * t->y) + (m[1][2] * t->z) + (m[1][3] * t->w);
	tuple->z = (m[2][0] * t->x) + (m[2][1] * t->y) + (m[2][2] * t->z) + (m[2][3] * t->w);
	tuple->w = (m[3][0] * t->x) + (m[3][1] * t->y) + (m[3][2] * t->z) + (m[3][3] * t->w);
	return (tuple);
}

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
			printf("%2.lf ", m[i][j]);
		printf("|\n");
	}
	printf("\n");
}

void	clear_matrix(double **m, int r)
{
	while (--r >= 0)
		free(m[r]);
	free(m);
}

void	get_submatrix(double **m, double **sub_m, int size, int r, int c)
{
	int		i;
	int		j;
	int		a;
	int		b;

	i = -1;
	a = 0;
	while (++i < size)
	{
		if (i == r)
			continue ;
		j = -1;
		b = 0;
		while (++j < size)
		{
			if (j == c)
				continue ;
			sub_m[a][b++] = m[i][j];
		}
		a++;
	}
}

double	**cofactor(double **m, int size)
{
	double	**sub_m;
	double	**cofactors = create_matrix(size, size);
	double	cof;
	int		i;
	int		j;

	sub_m = create_matrix(3, 3);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			get_submatrix(m, sub_m, size, i, j);
			cof = sub_m[0][0] * ((sub_m[1][1] * sub_m[2][2]) - ((sub_m[2][1] * sub_m[1][2])));
			cof -= sub_m[0][1] * ((sub_m[1][0] * sub_m[2][2]) - (sub_m[2][0] * sub_m[1][2]));
			cof += sub_m[0][2] * ((sub_m[1][0] * sub_m[2][1]) - (sub_m[2][0] * sub_m[1][1]));
			if ((i + j) % 2)
				cof *= -1;
			cofactors[i][j] = cof;
		}
	}
	clear_matrix(sub_m, 3);
	return (cofactors);
}

double	determinant(double **m, double **cofactors)
{
	double	det;
	int		i;

	det = 0;
	i = -1;
	while (++i < 4)
		det += m[0][i] * cofactors[0][i];
	return (det);
}

double	**inverse_matrix(double **m)
{
	double	**inverse;
	double	**cof;
	double	det;
	int		i;
	int		j;

	cof = cofactor(m, 4);
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
	return (inverse);
}

double	**transpose_matrix(double **m, int size)
{
	double	**transpose;
	int	i;
	int	j;

	transpose = create_matrix(size, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			transpose[i][j] = m[j][i];
	}
	return (transpose);
}
