NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS =	mandatory/miniRT.c \
		mandatory/main.c \
		mandatory/objects/add_object.c \
		mandatory/objects/create_object.c \
		mandatory/tuples/add_tuples.c \
		mandatory/tuples/substract_tuples.c \
		mandatory/tuples/scalar_multi.c \
		mandatory/tuples/trim_tuple.c \
		mandatory/tuples/normalize_tuple.c \
		mandatory/tuples/cross_product.c \
		mandatory/tuples/create_tuple.c \
		mandatory/tuples/multply_tuple.c \
		mandatory/tuples/magnitude.c \
		mandatory/tuples/dot_product.c\
		mandatory/tuples/display_tuple.c \
		mandatory/tuples/negate_tuple.c \
		mandatory/transformations/rotation.c \
		mandatory/transformations/scaling.c \
		mandatory/transformations/shearing.c \
		mandatory/transformations/translation.c \
		mandatory/transformations/view_transform.c \
		mandatory/ray/hit.c \
		mandatory/ray/create_ray.c \
		mandatory/ray/position.c \
		mandatory/ray/ray_for_pixel.c \
		mandatory/matrices/clear_matrix.c \
		mandatory/matrices/cofactor.c \
		mandatory/matrices/create_matrix.c \
		mandatory/matrices/trim_matrix.c \
		mandatory/matrices/determinant.c \
		mandatory/matrices/get_submatrix.c \
		mandatory/matrices/inverse_matrix.c \
		mandatory/matrices/matrix_multi.c \
		mandatory/matrices/matrix_x_tuple.c \
		mandatory/matrices/transpose_matrix.c \
		mandatory/matrices/display_matrix.c \
		mandatory/intersect/intersect_world.c \
		mandatory/intersect/plane_intersect.c \
		mandatory/intersect/sphere_intersect.c  \
		mandatory/intersect/intersect.c \
		mandatory/intersect/create_intersect.c \
		mandatory/intersect/intersections.c \
		mandatory/intersect/clear_intersecs.c \
		mandatory/intersect/inter_cyl.c \
		mandatory/intersect/cylinder_intersect.c \
		mandatory/utils/min.c \
		mandatory/utils/max.c \
		mandatory/utils/compare.c  \
		mandatory/utils/pixel_size.c \
		mandatory/utils/swap.c \
		mandatory/utils/strcmp.c \
		mandatory/utils/strlen.c \
		mandatory/utils/atod.c \
		mandatory/utils/set_value.c \
		mandatory/utils/is_valid.c \
		mandatory/utils/get_token.c \
		mandatory/vector/reflect.c \
		mandatory/vector/normal_at.c \
		mandatory/vector/cyl_normal_at.c \
		mandatory/vector/local_normal.c \
		mandatory/computation/prepare_computations.c \
		mandatory/color/color_at.c \
		mandatory/color/get_color.c \
		mandatory/color/lighting.c \
		mandatory/color/shade_hit.c \
		mandatory/color/render.c \
		mandatory/color/shadow.c \
		mandatory/parsing/parser.c \
		mandatory/parsing/parse_ambient.c \
		mandatory/parsing/parse_sphere.c \
		mandatory/parsing/parse_cylinder.c \
		mandatory/parsing/parse_plane.c \
		mandatory/gnl/get_line.c \
		mandatory/mlx/destroy_window.c \
		mandatory/mlx/mlx.c \
		mandatory/parsing/valid_extension.c \
		mandatory/parsing/valid_map.c \
		mandatory/parsing/parse_light.c \
		mandatory/parsing/phong_value.c \
		mandatory/parsing/coordinates.c \
		mandatory/parsing/orientation.c\
		mandatory/parsing/parse_color.c \
		mandatory/utils/error.c \
		mandatory/parsing/parse_camera.c \

# BONUS_SRCS =	bonus/miniRT.c \
# 		bonus/main.c \
# 		bonus/objects/add_object.c \
# 		bonus/objects/create_object.c \
# 		bonus/tuples/add_tuples.c \
# 		bonus/tuples/substract_tuples.c \
# 		bonus/tuples/scalar_multi.c \
# 		bonus/tuples/trim_tuple.c \
# 		bonus/tuples/normalize_tuple.c \
# 		bonus/tuples/cross_product.c \
# 		bonus/tuples/create_tuple.c \
# 		bonus/tuples/multply_tuple.c \
# 		bonus/tuples/magnitude.c \
# 		bonus/tuples/dot_product.c\
# 		bonus/tuples/display_tuple.c \
# 		bonus/tuples/negate_tuple.c \
# 		bonus/transformations/rotation.c \
# 		bonus/transformations/scaling.c \
# 		bonus/transformations/shearing.c \
# 		bonus/transformations/translation.c \
# 		bonus/transformations/view_transform.c \
# 		bonus/ray/hit.c \
# 		bonus/ray/create_ray.c \
# 		bonus/ray/position.c \
# 		bonus/ray/ray_for_pixel.c \
# 		bonus/matrices/clear_matrix.c \
# 		bonus/matrices/cofactor.c \
# 		bonus/matrices/create_matrix.c \
# 		bonus/matrices/trim_matrix.c \
# 		bonus/matrices/determinant.c \
# 		bonus/matrices/get_submatrix.c \
# 		bonus/matrices/inverse_matrix.c \
# 		bonus/matrices/matrix_multi.c \
# 		bonus/matrices/matrix_x_tuple.c \
# 		bonus/matrices/transpose_matrix.c \
# 		bonus/matrices/display_matrix.c \
# 		bonus/intersect/intersect_world.c \
# 		bonus/intersect/plane_intersect.c \
# 		bonus/intersect/sphere_intersect.c  \
# 		bonus/intersect/intersect.c \
# 		bonus/intersect/create_intersect.c \
# 		bonus/intersect/intersections.c \
# 		bonus/intersect/clear_intersecs.c \
# 		bonus/intersect/inter_cyl.c \
# 		bonus/intersect/cylinder_intersect.c \
# 		bonus/utils/min.c \
# 		bonus/utils/max.c \
# 		bonus/utils/compare.c  \
# 		bonus/utils/pixel_size.c \
# 		bonus/utils/swap.c \
# 		bonus/utils/strcmp.c \
# 		bonus/utils/strlen.c \
# 		bonus/utils/atod.c \
# 		bonus/utils/set_value.c \
# 		bonus/utils/is_valid.c \
# 		bonus/utils/get_token.c \
# 		bonus/vector/reflect.c \
# 		bonus/vector/normal_at.c \
# 		bonus/vector/cyl_normal_at.c \
# 		bonus/vector/local_normal.c \
# 		bonus/computation/prepare_computations.c \
# 		bonus/color/color_at.c \
# 		bonus/color/get_color.c \
# 		bonus/color/lighting.c \
# 		bonus/color/shade_hit.c \
# 		bonus/color/render.c \
# 		bonus/color/shadow.c \
# 		bonus/parsing/parser.c \
# 		bonus/parsing/parse_ambient.c \
# 		bonus/parsing/parse_sphere.c \
# 		bonus/parsing/parse_cylinder.c \
# 		bonus/parsing/parse_plane.c \
# 		bonus/gnl/get_line.c \
# 		bonus/mlx/destroy_window.c \
# 		bonus/mlx/mlx.c \
# 		bonus/parsing/valid_extension.c \
# 		bonus/parsing/valid_map.c \
# 		bonus/parsing/parse_light.c \
# 		bonus/parsing/phong_value.c \
# 		bonus/parsing/coordinates.c \
# 		bonus/parsing/orientation.c\
# 		bonus/parsing/parse_color.c \
# 		bonus/utils/error.c \
# 		bonus/parsing/parse_camera.c \

OBJS:=$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC)   $(CFLAGS) $(OBJS)  -L $(MLX_FLAGS)  -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all
