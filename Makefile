NAME = fdf
CCFLAGS = -Wextra -Wall -Werror -g
CC = cc
SRCSDIR = ./srcs/
SRCSLIST = $(appendix .c, main)
SRCS = $(appendix $(SRCSDIR), $(SRCSLIST))
OBJSDIR = ./objs/










SRC = your c code
GETNEXTLINE := get_next_line/*c
OBJS = $(SRC:.c=.o)
MLX = minilibx-linux/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "minilibx-linux" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	@if [ -d "minilibx-linux" ]; then \
	make clean -C minilibx-linux/; \
	fi
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
