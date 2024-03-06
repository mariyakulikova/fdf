NAME = fdf
CC = cc
CCFLAGS = -Wextra -Wall -Werror
RM = rm -f
DEBUG = -g

HEADDIR = .
HEADERS = fdf.h

SRCS =	main.c \
			hooks.c \
			window.c \
			parse_map.c \
			process_file.c \
			params.c \
			params2.c \
			draw.c \
			bresenham.c \
			transform.c \
			isometric.c \
			utils.c \

OBJSDIR = ./objs/
OBJSLIST = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSLIST))

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

MLXDIR = ../minilibx-linux/
MLX = ${MLXDIR}libmlx.a

LIBS = -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -L/usr/lib/X11 -lX11 -lm
INCS = -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}

all: $(NAME)

$(NAME): $(LIBFT) $(OBJSDIR) $(OBJS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $@ $(LIBS) $(INCS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJSDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

test: re
	./$(NAME) test_maps/42.fdf
