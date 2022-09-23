/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:49:37 by momeaizi          #+#    #+#             */
/*   Updated: 2022/09/22 11:44:19 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_tuple	*create_tuple(double x, double y, double z, double w);

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

void	display_tuple(t_tuple *t)
{
	printf("x = %2.lf\ny = %2.lf\nz = %2.lf\nw = %2.lf\n", t->x, t->y, t->z, t->w);
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

int	main()
{
	// t_tuple	*t = create_tuple(1, 2, 3, 1);
	double	**a = create_matrix(4, 4);
	// double	**b = create_matrix(3, 3);
	double	**m;
	// t_tuple	*tuple;
	a[0][0] = 9;
	a[0][1] = 3;
	a[0][2] = 0;
	a[0][3] = 9;
	a[1][0] = -5;
	a[1][1] = -2;
	a[1][2] = -6;
	a[1][3] = -3;
	a[2][0] = -4;
	a[2][1] = 9;
	a[2][2] = 6;
	a[2][3] = 4;
	a[3][0] = -7;
	a[3][1] = 6;
	a[3][2] = 6;
	a[3][3] = 2;
	// display_matrix(a, 4, 4);
	// m = inverse_matrix(a);
	// m = transpose_matrix(m, 4);
	// display_matrix(m, 4, 4);
	display_matrix(a, 4, 4);
	// printf("determinant = %2.lf\n", determinant(a, m));
	// system("leaks a.out");
}
	// b[0][0] = -2;
	// b[0][1] = 1;
	// b[0][2] = 2;
	// b[0][3] = 3;
	// b[1][0] = 3;
	// b[1][1] = 2;
	// b[1][2] = 1;
	// b[1][3] = -1;
	// b[2][0] = 4;
	// b[2][1] = 3;
	// b[2][2] = 6;
	// b[2][3] = 5;
	// b[3][0] = 1;
	// b[3][1] = 2;
	// b[3][2] = 7;
	// b[3][3] = 8;
	// m = matrix_multi(a, b, 4, 4);




	// tuple = matrix_x_tuple(a, t);
	// display_tuple(tuple);
	// b[0][0] = 1;
	// b[0][1] = 7;
	// b[0][2] = 3;
	// b[1][0] = 2;
	// b[1][1] = -9;
	// b[1][2] = 6;
	// b[2][0] = 7;
	// b[2][1] = 7;
	// b[2][2] = -9;