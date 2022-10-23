/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:00:39 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/23 10:40:32 by momeaizi         ###   ########.fr       */
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

typedef struct s_data
{
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

typedef struct s_material
{
	t_tuple	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}			t_material;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}				t_ray;

typedef struct s_object
{
	unsigned int		id;
	char				type;
	t_material			m;
	double				**t;
	double				**inv;
	double				**transp;
	struct	s_object	*next;
}	t_object;

typedef struct s_intersect
{
	double				t;
	t_object			*object;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_comp
{
	double			t;
	bool			inside;
	t_tuple			point;
	t_tuple			eyev;
	t_tuple			normalv;
	t_object		*obj;
}	t_comp;

typedef struct s_light
{
	t_tuple	position;
	t_tuple	intensity;
}			t_light;

typedef struct s_world
{
	t_light		light;
	t_object	*objects;
}	t_world;

/* ************************************************************************** */
/*                                 tuples.c                                   */
/* ************************************************************************** */
t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		scalar_multi(t_tuple tpl, double scalar);
t_tuple		substract_tuples(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);
double		dot_product(t_tuple a, t_tuple b);
t_tuple		add_tuples(t_tuple a, t_tuple b);
void		normalize_tuple(t_tuple *tuple);
t_tuple		negate_tuple(t_tuple tpl);
double		magnitude(t_tuple tuple);
void		display_tuple(t_tuple *t);

/* ************************************************************************** */
/*                                 matrices.c                                 */
/* ************************************************************************** */
double		**cofactor(double **m);
double		**trim_matrix(double **m);
double		**inverse_matrix(double **m);
void		clear_matrix(double **m, int r);
double		**create_matrix(int rows, int columns);
t_tuple		matrix_x_tuple(double **m, t_tuple t);
double		**transpose_matrix(double **m, int size);
double		determinant(double **m, double **cofactors);
double		determinant(double **m, double **cofactors);
void		display_matrix(double **m, int rows, int col);
void		get_submatrix(double **m, double **sub_m, int r, int c);
double		**matrix_multi(double **a, double **b, int rows, int columns);

/* ************************************************************************** */
/*                                 transformations.c                          */
/* ************************************************************************** */
double		**translation(double x, double y, double z);
double		**scaling(double x, double y, double z);
double		**shearing(int x, int y, int z);
double		**rotation_x(double r);
double		**rotation_y(double r);
double		**rotation_z(double r);


/* ************************************************************************** */
/*                                 rays.c                                     */
/* ************************************************************************** */
t_intersect	*hit(t_intersect *head);
t_tuple		position(t_ray ray, double t);
t_ray		create_ray(t_tuple origin, t_tuple direction);

/* ************************************************************************** */
/*                                 objects.c                                  */
/* ************************************************************************** */
t_object	*create_object(char type, double **t);


// ????????
double		*intersect(t_ray r);
void		intersections(t_intersect **head, t_object *obj, double t);
t_intersect	*create_intersect(double t, t_object *obj);
void		draw(t_data *img, t_world *world);
t_intersect	*intersect_world(t_world *world, t_ray r);

bool		compare(double a, double b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 		get_color(t_tuple color);
void		trim_tuple(t_tuple *tuple);
t_tuple		reflect(t_tuple lightv, t_tuple normal);
t_tuple		normal_at(t_object *obj, t_tuple *w_point);
t_tuple		lighting(t_material material, t_light light, t_tuple point, t_tuple eyev, t_tuple normal);
t_comp		prepare_computations(t_intersect intersection, t_ray ray);
#endif