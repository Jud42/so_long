/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:10:25 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 16:51:46 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_hook_event(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_end_game(data);
	if ((data->patrol == 1 && data->map->map[data->p_y][data->p_x] != \
	data->map->map[data->enem->r_y][data->enem->r_x]) || data->patrol == 0)
	{
		if (keycode == UP || keycode == 126)
			ft_move(data, 'y', -1);
		else if (keycode == DOWN || keycode == 125)
			ft_move(data, 'y', 1);
		else if (keycode == LEFT || keycode == 123)
			ft_move(data, 'x', -1);
		else if (keycode == RIGHT || keycode == 124)
			ft_move(data, 'x', 1);
		if (data->map->map[data->p_y][data->p_x] == 'E')
			ft_end_game(data);
		if (data->map->map[data->p_y][data->p_x] == 'R')
			ft_game_over(data);
	}
	return (0);
}

//final render displays
int	render_event(t_data *data)
{	
	data->counter = 0;
	put_background(data);
	read_map(data, data->map);
	mlx_hook(data->mlx_win, 2, 0, key_hook_event, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, mouse_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
