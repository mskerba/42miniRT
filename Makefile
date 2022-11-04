NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c   main.c\
		objects/add_object.c \
		objects/create_object.c \
		tuples/add_tuples.c \
		tuples/substract_tuples.c tuples/scalar_multi.c tuples/trim_tuple.c \
		tuples/normalize_tuple.c tuples/cross_product.c tuples/create_tuple.c tuples/multply_tuple.c \
		tuples/magnitude.c tuples/dot_product.c tuples/display_tuple.c tuples/negate_tuple.c \
		transformations/rotation.c transformations/scaling.c transformations/shearing.c \
		transformations/translation.c transformations/view_transform.c \
		ray/hit.c ray/create_ray.c ray/position.c ray/ray_for_pixel.c \
		matrices/clear_matrix.c matrices/cofactor.c matrices/create_matrix.c matrices/trim_matrix.c \
		matrices/determinant.c matrices/get_submatrix.c matrices/inverse_matrix.c \
		matrices/matrix_multi.c matrices/matrix_x_tuple.c matrices/transpose_matrix.c matrices/display_matrix.c \
		intersect/intersect_world.c intersect/plane_intersect.c intersect/sphere_intersect.c  intersect/intersect.c intersect/create_intersect.c \
		intersect/intersections.c intersect/clear_intersecs.c intersect/inter_cyl.c intersect/cylinder_intersect.c \
		utils/min.c utils/max.c utils/compare.c  utils/pixel_size.c utils/swap.c utils/strcmp.c \
		utils/strlen.c utils/atod.c utils/set_value.c utils/is_valid.c utils/get_token.c \
		vector/reflect.c vector/normal_at.c vector/cyl_normal_at.c vector/local_normal.c \
		computation/prepare_computations.c \
		color/color_at.c color/get_color.c color/lighting.c color/shade_hit.c \
		color/render.c color/shadow.c \
		parsing/parser.c parsing/parse_ambient.c parsing/parse_sphere.c parsing/parse_cylinder.c parsing/parse_plane.c \
		gnl/get_line.c mlx/destroy_window.c mlx/mlx.c \
		parsing/valid_extension.c parsing/valid_map.c parsing/parse_light.c parsing/phong_value.c parsing/coordinates.c parsing/orientation.c\
		parsing/parse_color.c \
		utils/error.c parsing/parse_camera.c \


all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

run : all
	@./miniRT

re : clean all