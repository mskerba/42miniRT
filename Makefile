NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c matrices.c rays.c transformations.c tuples.c objects.c main.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all