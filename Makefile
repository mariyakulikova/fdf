NAME = fdf
CC = cc
CCFLAGS = -Wextra -Wall -Werror
RM = rm -f
DEBUG = -g -fsanitize=address

HEADDIR = ./includes/
HEADLIST = fdf.h
HEADERS = $(addprefix $(HEADDIR), $(HEADLIST))

SRCSDIR = ./srcs/
SRCSLIST = main.c hooks.c window.c parse_map.c process_file.c params.c test.c
#SRCS = ./srcs/main.c
SRCS = $(addprefix $(SRCSDIR), $(SRCSLIST))

OBJSDIR = ./objs/
OBJSLIST = $(SRCSLIST:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSLIST))

LIBFTDIR = ./libft/
LIBFT = $(LIBFTDIR)libft.a

MLXDIR = ./minilibx-linux/
MLX = ${MLXDIR}libmlx.a

LIBS = -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -L/usr/lib/X11 -lX11 -lm
# LIBS			:= -L${LIBFTDIR} -L${MLXDIR} -lft -lmlx -lXext -lX11 -lm
INCS = -I${HEADDIR} -I${LIBFTDIR} -I${MLXDIR}

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJSDIR) $(OBJS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJS) -o $@ $(LIBS) $(INCS)

$(MLX):
	git submodule init
	git submodule update
	make -C $(MLXDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $(DEBUG) $(INCS) -c $< -o $@

clean:
	$(RM) -r $(OBJSDIR)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

test: all
	./$(NAME)

#bonustest:		bonus
#				./${BONUSNAME} test_maps/42.fdf
