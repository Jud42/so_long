/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:10:25 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 15:43:49 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_background(t_data *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	data->img->background = mlx_xpm_file_to_image(data->mlx, \
			BACKGROUND, &width, &height);
	while (++i < data->height_y / 64)
	{
		j = -1;
		while (++j < data->width_x / 64)
			mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->img->background, j * 64, i * 64);
	}
}
/*-------------------------------------------------------*/

//square for ecrase previous img
int	square_background(int data_x, int data_y, t_data *data)
{
	int	i;
	int	j;

	i = data_y * IMG_Y;
	j = data_x * IMG_X;
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->img->background, j, i);
	return (0);
}
/*-----------------------------------------------------*/

// put object on window
void	put_element(t_data *data, char *path)
{
	int	width;
	int	height;

	data->img->object = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->object, \
		(data->map->x * IMG_X), (data->map->y * IMG_Y));
}
/*-----------------------------------------------------*/

//put player on window
void	put_player(t_data *data, char *path)
{
	int	width;
	int	height;

	data->p_x = data->map->x;
	data->p_y = data->map->y;
	data->img->sprite = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->sprite, \
			(data->p_x * IMG_X), (data->p_y * IMG_Y));
}

void	put_move(t_data *data)
{
	char	*str;

	str = ft_itoa(data->counter);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img->texture, IMG_X / 1.8, IMG_Y / 4.5);
	mlx_string_put(data->mlx, data->mlx_win, \
			IMG_X, IMG_Y / 1.8, -1, "MOVE :");
	if (data->total_c >= 0)
		mlx_string_put(data->mlx, data->mlx_win,
			IMG_X * 2, IMG_Y / 1.8, -1, str);
	else
		mlx_string_put(data->mlx, data->mlx_win,
			IMG_X * 2, IMG_Y / 2, 0x00ff0000, str);
	free(str);
}
