NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c matrices.c rays.c transformations.c objects.c main.c \
		tuples/normalize_tuple.c tuples/cross_product.c tuples/create_tuple.c \
		tuples/add_tuples.c tuples/substract_tuples.c tuples/scalar_multi.c \
		tuples/magnitude.c tuples/dot_product.c tuples/display_tuple.c tuples/negate_tuple.c \

all : $(NAME)

$(NAME) : $(SRCS)
	@$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

run : all
	@./miniRT

re : clean all