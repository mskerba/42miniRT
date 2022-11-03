/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:00:39 by mskerba           #+#    #+#             */
/*   Updated: 2022/11/03 13:22:04 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <limits.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# define EPSILON 0.000010
# define BUFFER_SIZE 1000

enum
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

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
	double				cyl_min;
	double				cyl_max;
	struct s_object		*next;
}	t_object;

typedef struct s_intersect
{
	double				t;
	t_object			*object;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_ambient
{
	double	ambient;
	t_tuple	color;
}			t_ambient;

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
	t_ambient	ambient;
	double		diffuse;
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

typedef struct s_phong
{
	t_tuple	effective_c;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	factor;
	double	reflect_dot_eye;
	double	light_dot_norm;
}	t_phong;

/* ************************************************************************** */
/*                                 miniRT                                     */
/* ************************************************************************** */
void		minirt(t_world *world, t_mlx *img, int ac, char *s);

/* ************************************************************************** */
/*                                 tuples                                     */
/* ************************************************************************** */
t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		scalar_multi(t_tuple tpl, double scalar);
t_tuple		multiply_tuple(t_tuple *a, t_tuple *b);
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
t_tuple		matrix_x_tuple(double **m, t_tuple t);
double		**create_matrix(int rows, int columns);
double		**transpose_matrix(double **m, int size);
double		determinant(double **m, double **cofactors);
double		determinant(double **m, double **cofactors);
void		display_matrix(double **m, int rows, int col);
double		**matrix_multi(double **a, double **b);
void		get_submatrix(double **m, double **sub_m, int r, int c);

/* ************************************************************************** */
/*                                 transformations                            */
/* ************************************************************************** */
void		view_transform(t_camera *c, t_tuple from, t_tuple to, t_tuple up);
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
double		*inter_cyl(t_ray r);
double		*intersect(t_ray r, double *t);
void		clear_intersecs(t_intersect **intersecs);
t_intersect	*create_intersect(double t, t_object *obj);
t_intersect	*intersect_world(t_world *world, t_ray *r);
t_intersect	*local_intersect(t_world *world, t_ray *r);
void		intersections(t_intersect **head, t_object *obj, double t);
void		plane_inter(t_object *plane, t_ray *r, t_intersect **inter);
void		sphere_inter(t_object *sphere, t_ray *r, t_intersect **inter);
void		cylindre_inter(t_object *cylindre, t_ray *r, t_intersect **inter);

/* ************************************************************************** */
/*                                 utiles                                     */
/* ************************************************************************** */
char		*get_token(char *s, char c, int len);
double		set_value(char *s, char c, int len, double *range);
int			ft_strcmp(char *s1, char *s2);
bool		compare(double a, double b);
void		swap(double *a, double *b);
void		error(char *s1, char *s2);
void		pixel_size(t_camera *c);
double		max(double a, double b);
double		min(double a, double b);
void		is_valid(char *token);
int			ft_strlen(char *s);
double		d_atoi(char *s);
double		atod(char *s);

/* ************************************************************************** */
/*                                 gnl                                        */
/* ************************************************************************** */
char		*get_line(int fd);
char		*ft_strjoin(char c, char *str);
void		ft_strcpy(char	*dst, char	*src, char c);

/* ************************************************************************** */
/*                                 vector                                     */
/* ************************************************************************** */
t_tuple		local_normal_at(t_object *obj, t_tuple *w_point);
t_tuple		cyl_normal_at(t_object *obj, t_tuple *w_point);
t_tuple		normal_at(t_object *obj, t_tuple *w_point);
t_tuple		reflect(t_tuple lightv, t_tuple normal);

/* ************************************************************************** */
/*                                 computations                               */
/* ************************************************************************** */
t_comp		prepare_computations(t_intersect *intersecs, t_ray *r);

/* ************************************************************************** */
/*                                 color                                      */
/* ************************************************************************** */
int			get_color(t_tuple color);
int			color_at(t_world *world, t_ray *r);
t_tuple		shade_hit(t_world *world, t_comp *comps);
bool		is_shadowed(t_world *world, t_tuple point);
void		render(t_mlx *img, t_world *world, t_camera *c);
t_tuple		lighting(t_world *w, t_comp *comps, t_light *light, bool shadowed);

/* ************************************************************************** */
/*                                 parse                                      */
/* ************************************************************************** */
void		parse_cylindre(t_world *w, char *s, int len);
void		parse_camera(t_camera *c, char *s, int len);
void		parser(t_world *world, t_camera *c, int fd);
void		parse_ambient(t_world *w, char *s, int len);
void		parse_sphere(t_world *w, char *s, int len);
void		parse_light(t_world	*w, char *s, int len);
void		phong_value(t_world *w, char *s, int len);
void		parse_plan(t_world *w, char *s, int len);
double		**coordinates(char *s, int len);
double		**orientation(char *s, int len);
t_tuple		parse_color(char *s, int len, char c);
int			valid_map(int ac, char *s);
void		valid_extension(char *s);

/* ************************************************************************** */
/*                                 mlx                                        */
/* ************************************************************************** */
int			destroy(t_mlx *mlx);
int			key_hook(int key, t_mlx *mlx);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif