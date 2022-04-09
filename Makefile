
NAME		= prog
LIB_PRINTF_DIR		= ./libft/ft_printf
MLX_DIR		= ./minilibx
MLX			= libmlx.a
SRCS	= utils_map.c	so_long.c	display.c	close_win.c	read_map.c	move.c	init.c	end_game.c	parse_map.c	render_event.c
DIR_S	= src
DIR_O	= temp
RM 	= rm -rf
FRAMEWORK = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDE	= -I./include -I./libft -I./libft/ft_printf/ -I./minilibx 
LIB_A	= -L$(LIB_PRINTF_DIR) $(LIB_PRINTF_DIR)/libft_printf.a
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
	make -C $(LIB_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OB) $(INCLUDE) $(LIB_A) $(FRAMEWORK) -o $@

all :	$(NAME)

clean	:
		$(RM) $(DIR_O)
		make clean -C $(LIB_PRINTF_DIR)

fclean	: clean 
	$(RM) $(NAME) $(MLX) $(MLX_DIR)/$(MLX)
	make fclean -C $(LIB_PRINTF_DIR)

re	: fclean $(NAME)

.PHONY:	all clean fclean re

