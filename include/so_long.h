/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:55:20 by rmamison          #+#    #+#             */
/*   Updated: 2022/03/31 20:37:26 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define	UP 13	//W
#define	DOWN 1	//S	
#define	LEFT 0	//A
#define	RIGHT 2	//D
#define	ESC 53
#define	IMG_X 32
#define IMG_Y 32
#define BACKGR_PIXEL 0x00000033
#define RED	0x00ff0000
#define	SPRITE_UP	"./gametiles/sprite/up.xpm"
#define	SPRITE_DOWN	"./gametiles/sprite/down.xpm"
#define	SPRITE_RIGHT "./gametiles/sprite/right.xpm"
#define	SPRITE_LEFT	"./gametiles/sprite/left.xpm"
typedef struct	s_map{
	char	**map;
	int	x;
	int	y;
}	t_map;

typedef struct	s_img{ //struct for data image
	void	*mlx_img;
	void	*object;
	void	*sprite;
	void	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;	
}	t_img;

typedef struct	s_data{ //struct for init 
	void 	*mlx;
	void	*mlx_win;
	int		width_x;
	int		height_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		total_c;
	t_img	*img;
	t_map	*map;
}	t_data;

int	exit_key(t_data *data);
int	mouse_exit(t_data	*data);
int	square_background(t_data *data, int color);
void	tab_map(char	*file, t_map *p);
void	window_x_y(char	**av, t_data *data);
int		rander(t_data	*data);
int		key_hook_event(int	keycode, t_data	*data);
void	read_tab(t_data	*data, t_map	*map);
int	define_img(char	element);
void	put_element(t_data	*data, char	*path);
void	put_player(t_data	*data, char	*path);
void	display_back(t_data	*data);
void	init_img(t_data	*data, t_img *img);

# endif 
