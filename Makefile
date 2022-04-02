
NAME	= prog
LIB_DIR	= ./libft
MLX_DIR	= ./minilibx
MLX	= libmlx.a
SRCS	= count_map.c	so_long.c	display.c	exit_key.c	mouse_close_win.c	read_map.c	move.c
DIR_S	= src
DIR_O	= temp
RM 	= rm -rf
FRAMEWORK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDE	= -I./include -I./libft -I./minilibx
LIB_A	= -L./libft -lft 
CFLAGS	= -g -Wall -Wextra -Werror -fsanitize=address
DFLAGS	= 
CC	= clang


SR	=	$(addprefix $(DIR_S)/, $(SRCS))
OB	=	$(addprefix $(DIR_O)/, $(SRCS:%.c=%.o))


$(DIR_O)/%.o : $(DIR_S)/%.c
	mkdir -p temp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(DFLAGS)

$(NAME) : $(OB)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OB) $(INCLUDE) $(LIB_A) $(FRAMEWORK) -o $@

all :	$(NAME)

clean	:
		$(RM) $(DIR_O)
		$(RM) libft/*.o

fclean	: clean 
	$(RM) $(NAME) $(MLX) $(MLX_DIR)/$(MLX)
	$(RM) $(LIB_DIR)/libft.a

re	: fclean $(NAME)

.PHONY:	all clean fclean re

