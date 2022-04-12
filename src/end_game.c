/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:13:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 17:23:42 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	while (*data->map->map)
	{
		free(*data->map->map);
		data->map->map++;
	}
	data->map->map = NULL;
}

void	ft_end_game(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->img->mlx_img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_map(data);
	free(data->mlx);
	exit(0);
}

void	ft_game_over(t_data *data)
{
	int	width;
	int	height;

	data->img->object = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/game_over.xpm", &width, &height);
	square_background(data->enem->r_x, data->enem->r_y, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->object, \
			data->width_x / 2 - 96, data->height_y / 3);
}
