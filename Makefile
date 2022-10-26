NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c main.c \
		objects/add_object.c objects/create_object.c \
		tuples/add_tuples.c tuples/substract_tuples.c tuples/scalar_multi.c tuples/trim_tuple.c\
		tuples/normalize_tuple.c tuples/cross_product.c tuples/create_tuple.c \
		tuples/magnitude.c tuples/dot_product.c tuples/display_tuple.c tuples/negate_tuple.c \
		transformations/rotation.c transformations/scaling.c transformations/shearing.c \
		transformations/translation.c \
		ray/hit.c ray/create_ray.c ray/position.c ray/ray_for_pixel.c \
		matrices/clear_matrix.c matrices/cofactor.c matrices/create_matrix.c matrices/trim_matrix.c \
		matrices/determinant.c matrices/get_submatrix.c matrices/inverse_matrix.c\
		matrices/matrix_multi.c matrices/matrix_x_tuple.c matrices/transpose_matrix.c matrices/display_matrix.c\

all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

run : all
	@./miniRT

re : clean all