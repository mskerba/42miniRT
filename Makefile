NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c   \
		objects/add_object.c objects/create_object.c \
		tuples/add_tuples.c tuples/substract_tuples.c tuples/scalar_multi.c tuples/trim_tuple.c\
		tuples/normalize_tuple.c tuples/cross_product.c tuples/create_tuple.c \
		tuples/magnitude.c tuples/dot_product.c tuples/display_tuple.c tuples/negate_tuple.c \
		transformations/rotation.c transformations/scaling.c transformations/shearing.c \
		transformations/translation.c transformations/view_transform.c\
		ray/hit.c ray/create_ray.c ray/position.c ray/ray_for_pixel.c \
		matrices/clear_matrix.c matrices/cofactor.c matrices/create_matrix.c matrices/trim_matrix.c \
		matrices/determinant.c matrices/get_submatrix.c matrices/inverse_matrix.c\
		matrices/matrix_multi.c matrices/matrix_x_tuple.c matrices/transpose_matrix.c matrices/display_matrix.c\
		intersect/intersect_world.c intersect/plane_intersect.c intersect/sphere_intersect.c  intersect/intersect.c intersect/create_intersect.c \
		intersect/intersections.c intersect/clear_intersecs.c intersect/inter_cyl.c intersect/cylindre_intersect.c  \
		utiles/min.c utiles/max.c utiles/compare.c utiles/mlx.c utiles/pixel_size.c utiles/ft_swap.c \
		vector/reflect.c vector/normal_at.c vector/cyl_normal_at.c vector/local_normal.c \
		computation/prepare_computations.c \
		color/color_at.c color/get_color.c color/lighting.c color/shade_hit.c \
		color/draw.c color/shadow.c \

all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

run : all
	@./miniRT

re : clean all