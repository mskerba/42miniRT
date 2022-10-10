/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:45:39 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 18:52:03 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define EPSILON 0.00001

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

/* ************************************************************************** */
/*                                 tuples.c                          		  */
/* ************************************************************************** */
void	display_tuple(t_tuple *t);
t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple	*add_tuples(t_tuple *a, t_tuple *b);
t_tuple	*substract_tuples(t_tuple *a, t_tuple *b);
t_tuple	*negate_tuple(t_tuple *tpl);
t_tuple	*scalar_multi(t_tuple *tpl, double scalar);
double	magnitude(t_tuple *tuple);
void	normalize_tuple(t_tuple *tuple);
double	dot_product(t_tuple *a, t_tuple *b);
t_tuple	*cross_product(t_tuple *a, t_tuple *b);

/* ************************************************************************** */
/*                                 matrices.c                          		  */
/* ************************************************************************** */
void	display_matrix(double **m, int rows, int col);
double	**create_matrix(int rows, int columns);
double	**matrix_multi(double **a, double **b, int rows, int columns);
t_tuple	*matrix_x_tuple(double **m, t_tuple *t);
void	clear_matrix(double **m, int r);
void	get_submatrix(double **m, double **sub_m, int size, int r, int c);
double	**cofactor(double **m, int size);
double	determinant(double **m, double **cofactors);
double	determinant(double **m, double **cofactors);
double	**inverse_matrix(double **m);
double	**transpose_matrix(double **m, int size);


/* ************************************************************************** */
/*                                 transformations.c                          */
/* ************************************************************************** */
double  **translation(double x, double y, double z);
double  **rotation_x(double r);
double  **rotation_y(double r);
double  **rotation_z(double r);
double  **scaling(double x, double y, double z);
double  **shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y);

#endif