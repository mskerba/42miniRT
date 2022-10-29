/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:00:39 by mskerba           #+#    #+#             */
/*   Updated: 2022/10/29 10:36:43 by momeaizi         ###   ########.fr       */
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

# define EPSILON 0.000010

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
	t_tuple			over_point;
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
	t_light		*light;
	t_object	*objects;
}	t_world;

typedef struct s_camera
{
	double	hsize;
	double	vsize;
	double	half_width;
	double	half_height;
	double	pixel_size;
	double	field_of_view;
	double	**transf;
	double	**inv;
}	t_camera;

/* ************************************************************************** */
/*                                 tuples                                     */
/* ************************************************************************** */
t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		scalar_multi(t_tuple tpl, double scalar);
t_tuple		substract_tuples(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);
double		dot_product(t_tuple a, t_tuple b);
t_tuple		add_tuples(t_tuple a, t_tuple b);
void		normalize_tuple(t_tuple *tuple);
void		trim_tuple(t_tuple *tuple);
t_tuple		negate_tuple(t_tuple tpl);
double		magnitude(t_tuple tuple);
void		display_tuple(t_tuple *t);

/* ************************************************************************** */
/*                                 matrices                                   */
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
/*                                 transformations                            */
/* ************************************************************************** */
double		**view_transform(t_tuple from, t_tuple to, t_tuple up);
double		**translation(double x, double y, double z);
double		**scaling(double x, double y, double z);
double		**shearing(int x, int y, int z);
double		**rotation_x(double r);
double		**rotation_y(double r);
double		**rotation_z(double r);


/* ************************************************************************** */
/*                                 rays                                       */
/* ************************************************************************** */
t_intersect	*hit(t_intersect *head);
t_tuple		position(t_ray ray, double t);
t_ray		create_ray(t_tuple origin, t_tuple direction);
t_ray		ray_for_pixel(t_camera *c, double px, double py);

/* ************************************************************************** */
/*                                 objects                                    */
/* ************************************************************************** */
void		add_object(t_object **obj, char type, double **t);
t_object	*create_object(char type, double **t);

/* ************************************************************************** */
/*                                 intersect                                  */
/* ************************************************************************** */
double		*intersect(t_ray r);
double		*inter_cyl(t_ray r);
void		clear_intersecs(t_intersect **intersecs);
t_intersect	*intersect_world(t_world *world, t_ray *r);
t_intersect	*local_intersect(t_world *world, t_ray *r);
t_intersect	*create_intersect(double t, t_object *obj);
void		cylindre_inter(t_object *cylindre, t_ray *r, t_intersect **inter);
void		plane_inter(t_object *plane, t_ray *r, t_intersect **inter);
void		intersections(t_intersect **head, t_object *obj, double t);

/* ************************************************************************** */
/*                                 utiles                                     */
/* ************************************************************************** */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			key_hook(int key, t_data *img);
bool		compare(double a, double b);
void		pixel_size(t_camera *c);
double		max(double a, double b);
double		min(double a, double b);

/* ************************************************************************** */
/*                                 vector                                     */
/* ************************************************************************** */
t_tuple		reflect(t_tuple lightv, t_tuple normal);
t_tuple		normal_at(t_object *obj, t_tuple *w_point);
t_tuple		cyl_normal_at(t_object *obj, t_tuple *w_point);
t_tuple		local_normal_at(t_object *obj, t_tuple *w_point);

/* ************************************************************************** */
/*                                 computations                               */
/* ************************************************************************** */
t_comp		prepare_computations(t_intersect *intersecs, t_ray *r);

/* ************************************************************************** */
/*                                 color                                      */
/* ************************************************************************** */
int 		get_color(t_tuple color);
int			color_at(t_world *world, t_ray *r);
t_tuple		shade_hit(t_world *world, t_comp *comps);
t_tuple		lighting(t_comp *comps, t_light *light, bool shadowed);




// ????????
bool	is_shadowed(t_world *world, t_tuple point);
void		draw(t_data *img, t_world *world, t_camera *c);
#endif