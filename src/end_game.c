/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:13:26 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/08 12:48:18 by rmamison         ###   ########.fr       */
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
