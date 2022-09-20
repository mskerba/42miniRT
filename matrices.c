/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:49:37 by momeaizi          #+#    #+#             */
/*   Updated: 2022/09/20 12:04:48 by momeaizi         ###   ########.fr       */
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

double	cofactor(double **m, int r, int c)
{
	double	cof;

	cof = m[0][0] * ((m[1][1] * m[2][2]) - ((m[2][1] * m[1][2])));
	cof -= m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2]));
	cof += m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));
	if ((r + c) % 2)
		cof *= -1;
	return (cof);
}

double	**create_submatrix(double **m, int size)
{
	double	**sub_m;
	double	**cofactors = create_matrix(size, size);
	int	a;
	int	b;
	int	i;
	int	j;
	int	r;
	int	c;

	r = -1;
	while (++r < size)
	{
		sub_m = create_matrix(size - 1, size - 1);
		c = -1;
		while (++c < size)
		{
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
			cofactors[r][c] = cofactor(sub_m, r, c);
		}
	}
	display_matrix(cofactors, 4, 4);
	return (cofactors);
}

int	main()
{
	// t_tuple	*t = create_tuple(1, 2, 3, 1);
	double	**a = create_matrix(4, 4);
	// double	**b = create_matrix(3, 3);
	double	**m;
	// t_tuple	*tuple;
	a[0][0] = -2;
	a[0][1] = -8;
	a[0][2] = 3;
	a[0][3] = 5;
	a[1][0] = -3;
	a[1][1] = 1;
	a[1][2] = 7;
	a[1][3] = 3;
	a[2][0] = 1;
	a[2][1] = 2;
	a[2][2] = -9;
	a[2][3] = 6;
	a[3][0] = -6;
	a[3][1] = 7;
	a[3][2] = 7;
	a[3][3] = -9;
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
	display_matrix(a, 4, 4);
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
	create_submatrix(a, 4);
}