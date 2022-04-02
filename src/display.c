/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:10:25 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/01 14:08:31 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	my_mlx_put_pixel(t_img	*img, int x, int y, int color) //put pixel in img
{
	char	*pixel;

	pixel	= img->addr + (y * img->line_lenght + x * (img->bpp / 8));
	*(unsigned int*)pixel = color;
}

/*-----------------------------------------------------*/
void put_background(t_data	*data, int	color) //create pix background & put in img endlessly 
{
	int	i;
	int	j;

	i = 32;
	while(i < data->height_y)	
	{
		j = 0;
		while (j < data->width_x)
			my_mlx_put_pixel(data->img, j++, i, color);
		++i;
	}	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->mlx_img, 0, 0);
}
/*-------------------------------------------------------*/
int	square_background(t_data	*data, int	color)
{
	int	x;
	int	y;

	y = data->p_y * IMG_Y + 32; /* +32 display move*/
	while(y < data->p_y * IMG_Y + 64) /* +64 (32 for display move)*/
	{
		x = data->p_x * IMG_X;
		while(x < data->p_x * IMG_X + 32)
			mlx_pixel_put(data->mlx, data->mlx_win, x++, y, color);
		y++;
	}	
	//mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->mlx_img, 0, 0);
	return	(0);
}

/*-----------------------------------------------------*/
void	put_element(t_data	*data,	char	*path) // put object on window
{
	int	width;
	int	height;
	data->img->object = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->object, (data->map->x * IMG_X), (data->map->y * IMG_Y + 32)); /* + 32  reserve space for move display*/
}

/*-----------------------------------------------------*/
void	put_player(t_data	*data, char	*path) //put player on window
{
	int	width;
	int	height;

	data->p_x = data->map->x;
	data->p_y = data->map->y;
	data->img->sprite = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->sprite, (data->p_x * IMG_X), (data->p_y * IMG_Y + 32)); /* 32 reserve spcace for move display*/
}

/*----------------------------------------------------*/


/*----------------------------------------------------*/
int	rander(t_data	*data) //final render displays
{	
	data->counter = 0;
	put_background(data, BACKGR_PIXEL);
	read_tab(data, data->map);
	mlx_hook(data->mlx_win, 17, 0, mouse_exit, data);
	mlx_key_hook(data->mlx_win, key_hook_event, data);
	return (0);
}
