/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:45:39 by momeaizi          #+#    #+#             */
/*   Updated: 2022/10/10 20:50:30 by momeaizi         ###   ########.fr       */
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

typedef	struct s_ray
{
	t_tuple	*origin;
	t_tuple	*direction;
}				t_ray;

/* ************************************************************************** */
/*                                 tuples.c                          		  */
/* ************************************************************************** */
t_tuple	*create_tuple(double x, double y, double z, double w);
t_tuple	*scalar_multi(t_tuple *tpl, double scalar);
t_tuple	*substract_tuples(t_tuple *a, t_tuple *b);
t_tuple	*cross_product(t_tuple *a, t_tuple *b);
double	dot_product(t_tuple *a, t_tuple *b);
t_tuple	*add_tuples(t_tuple *a, t_tuple *b);
void	normalize_tuple(t_tuple *tuple);
t_tuple	*negate_tuple(t_tuple *tpl);
double	magnitude(t_tuple *tuple);
void	display_tuple(t_tuple *t);

/* ************************************************************************** */
/*                                 matrices.c                          		  */
/* ************************************************************************** */
double	**inverse_matrix(double **m);
void	clear_matrix(double **m, int r);
double	**cofactor(double **m, int size);
double	**create_matrix(int rows, int columns);
t_tuple	*matrix_x_tuple(double **m, t_tuple *t);
double	**transpose_matrix(double **m, int size);
double	determinant(double **m, double **cofactors);
double	determinant(double **m, double **cofactors);
void	display_matrix(double **m, int rows, int col);
double	**matrix_multi(double **a, double **b, int rows, int columns);
void	get_submatrix(double **m, double **sub_m, int size, int r, int c);


/* ************************************************************************** */
/*                                 transformations.c                          */
/* ************************************************************************** */
double  **rotation_x(double r);
double  **rotation_y(double r);
double  **rotation_z(double r);
double  **scaling(double x, double y, double z);
double  **translation(double x, double y, double z);
double  **shearing(double x_y, double x_z, double y_x, double y_z, double z_x, double z_y);

/* ************************************************************************** */
/*                                 rays.c                          			  */
/* ************************************************************************** */
t_ray	*create_ray(t_tuple *origin, t_tuple *direction);
t_tuple	*position(t_ray *ray, double t);


#endif