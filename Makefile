NAME = miniRT

BONUS_NAME = miniRT_bonus

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

BONUS_SRCS =	bonus/miniRT_bonus.c \
		bonus/main_bonus.c \
		bonus/objects/add_object_bonus.c \
		bonus/objects/create_object_bonus.c \
		bonus/tuples/add_tuples_bonus.c \
		bonus/tuples/substract_tuples_bonus.c \
		bonus/tuples/scalar_multi_bonus.c \
		bonus/tuples/trim_tuple_bonus.c \
		bonus/tuples/normalize_tuple_bonus.c \
		bonus/tuples/cross_product_bonus.c \
		bonus/tuples/create_tuple_bonus.c \
		bonus/tuples/multply_tuple_bonus.c \
		bonus/tuples/magnitude_bonus.c \
		bonus/tuples/dot_product_bonus.c \
		bonus/tuples/display_tuple_bonus.c \
		bonus/tuples/negate_tuple_bonus.c \
		bonus/transformations/rotation_bonus.c \
		bonus/transformations/scaling_bonus.c \
		bonus/transformations/shearing_bonus.c \
		bonus/transformations/translation_bonus.c \
		bonus/transformations/view_transform_bonus.c \
		bonus/ray/hit_bonus.c \
		bonus/ray/create_ray_bonus.c \
		bonus/ray/position_bonus.c \
		bonus/ray/ray_for_pixel_bonus.c \
		bonus/matrices/clear_matrix_bonus.c \
		bonus/matrices/cofactor_bonus.c \
		bonus/matrices/create_matrix_bonus.c \
		bonus/matrices/trim_matrix_bonus.c \
		bonus/matrices/determinant_bonus.c \
		bonus/matrices/get_submatrix_bonus.c \
		bonus/matrices/inverse_matrix_bonus.c \
		bonus/matrices/matrix_multi_bonus.c \
		bonus/matrices/matrix_x_tuple_bonus.c \
		bonus/matrices/transpose_matrix_bonus.c \
		bonus/matrices/display_matrix_bonus.c \
		bonus/intersect/intersect_world_bonus.c \
		bonus/intersect/plane_intersect_bonus.c \
		bonus/intersect/sphere_intersect_bonus.c  \
		bonus/intersect/intersect_bonus.c \
		bonus/intersect/create_intersect_bonus.c \
		bonus/intersect/intersections_bonus.c \
		bonus/intersect/clear_intersecs_bonus.c \
		bonus/intersect/inter_cyl_bonus.c \
		bonus/intersect/cylinder_intersect_bonus.c \
		bonus/utils/min_bonus.c \
		bonus/utils/max_bonus.c \
		bonus/utils/compare_bonus.c  \
		bonus/utils/pixel_size_bonus.c \
		bonus/utils/swap_bonus.c \
		bonus/utils/strcmp_bonus.c \
		bonus/utils/strlen_bonus.c \
		bonus/utils/atod_bonus.c \
		bonus/utils/set_value_bonus.c \
		bonus/utils/is_valid_bonus.c \
		bonus/utils/get_token_bonus.c \
		bonus/vector/reflect_bonus.c \
		bonus/vector/normal_at_bonus.c \
		bonus/vector/cyl_normal_at_bonus.c \
		bonus/vector/local_normal_bonus.c \
		bonus/computation/prepare_computations_bonus.c \
		bonus/color/color_at_bonus.c \
		bonus/color/get_color_bonus.c \
		bonus/color/lighting_bonus.c \
		bonus/color/shade_hit_bonus.c \
		bonus/color/render_bonus.c \
		bonus/color/shadow_bonus.c \
		bonus/parsing/parser_bonus.c \
		bonus/parsing/parse_ambient_bonus.c \
		bonus/parsing/parse_sphere_bonus.c \
		bonus/parsing/parse_cylinder_bonus.c \
		bonus/parsing/parse_plane_bonus.c \
		bonus/gnl/get_line_bonus.c \
		bonus/mlx/destroy_window_bonus.c \
		bonus/mlx/mlx_bonus.c \
		bonus/parsing/valid_extension_bonus.c \
		bonus/parsing/valid_map_bonus.c \
		bonus/parsing/parse_light_bonus.c \
		bonus/parsing/phong_value_bonus.c \
		bonus/parsing/coordinates_bonus.c \
		bonus/parsing/orientation_bonus.c\
		bonus/parsing/parse_color_bonus.c \
		bonus/utils/error_bonus.c \
		bonus/parsing/parse_camera_bonus.c \

OBJS:=$(SRCS:.c=.o)

BONUS_OBJS:=$(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC)   $(CFLAGS) $(OBJS)  -L $(MLX_FLAGS)  -o $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC)   $(CFLAGS) $(BONUS_OBJS)  -L $(MLX_FLAGS)  -o $(BONUS_NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : clean all
