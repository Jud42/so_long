/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:10:25 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/09 19:52:55 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_hook_event(int keycode, t_data *data)
{
	if (keycode == UP)
		ft_move(data, 'y', -1);
	else if (keycode == DOWN)
		ft_move(data, 'y', 1);
	else if (keycode == LEFT)
		ft_move(data, 'x', -1);
	else if (keycode == RIGHT)
		ft_move(data, 'x', 1);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_end_game(data);
	return (0);
}

//final render displays
int	render_event(t_data *data)
{	
	data->counter = 0;
	put_background(data);
	read_map(data, data->map);
	mlx_hook(data->mlx_win, 2, 1L << 0, exit_key, data);
	mlx_hook(data->mlx_win, 17, 1L << 0, mouse_exit, data);
	mlx_key_hook(data->mlx_win, key_hook_event, data);
	mlx_loop(data->mlx);
	return (0);
}
