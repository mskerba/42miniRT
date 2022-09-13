NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

SRCS = miniRT.c

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(CFLAGS) $(SRCS) -L $(MLX_FLAGS) -o $(NAME)

clean :
	rm -f $(NAME)

re : clean all