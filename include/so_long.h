/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:55:20 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/13 17:58:54 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# define ESC 53 //Escape
# define UP 13	 //W
# define DOWN 1	 //S	
# define LEFT 0	 //A
# define RIGHT 2 //D
# define IMG_X 64
# define IMG_Y 64
# define BACKGROUND "./gametiles/background.xpm"
# define SPRITE_UP "./gametiles/sprite/up.xpm"
# define SPRITE_DOWN "./gametiles/sprite/down.xpm"
# define SPRITE_RIGHT "./gametiles/sprite/right.xpm"
# define SPRITE_LEFT "./gametiles/sprite/left.xpm"

typedef struct s_map{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_img{ //struct for data image
	void	*mlx_img;
	void	*addr;
	int		endian;
	int		bpp;
	int		line_lenght;
	void	*background;	
	void	*object;
	void	*texture;
	void	*exit;
	void	*sprite;
	void	*s_up;
	void	*s_down;
	void	*s_left;
	void	*s_right;
}	t_img;

typedef struct s_enem{
	int		r_x;
	int		r_y;
	int		count;
	void	*img_0;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
}	t_enem;

typedef struct s_data{ //struct for init 
	void	*mlx;
	void	*mlx_win;
	int		width_x;
	int		height_y;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		counter;
	int		total_c;
	int		patrol;
	int		play_i;
	int		exit_i;
	t_img	*img;
	t_map	*map;
	t_enem	*enem;
}	t_data;

int		ft_parse_arg(int ac, char **av);
void	parse_map(t_data *data);
int		mouse_exit(t_data	*data);
void	put_background(t_data *data);
int		square_background(int data_x, int data_y, t_data *data);
void	create_map(char	*file, t_data *data);
void	window_x_y(char	**av, t_data *data);
int		render_event(t_data	*data);
int		key_hook_event(int keycode, t_data *data);
void	read_map(t_data	*data, t_map	*map);
int		define_img(char element);
void	put_element(t_data	*data, char	*path);
void	put_player(t_data	*data, char	*path);
void	anim_enem(t_data *data);
void	init_data_mlx(t_data	*data);
void	init_img(t_data *data);
void	error_msg(void *ptr_mlx, char *s, t_data *data);
void	ft_end_game(t_data *data);
void	free_map(t_data *data);
void	ft_end_game(t_data	*data);
void	ft_move(t_data *data, char pos, int move);
void	put_move(t_data *data);
void	ft_game_over(t_data *data);
#endif 
