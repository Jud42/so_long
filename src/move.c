/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:29:16 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 16:27:28 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*dans cette fonction je vais analyser la direction 
 et push image qui correspond a ce dernier*/

void	parse_move(t_data *data, char pos, int move)
{
	if (pos == 'y' && move == -1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->s_up, \
				(data->p_x * IMG_X), (data->p_y * IMG_Y));
	else if (pos == 'y' && move == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->s_down, \
				(data->p_x * IMG_X), (data->p_y * IMG_Y));
	else if (pos == 'x' && move == -1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->s_left, \
				(data->p_x * IMG_X), (data->p_y * IMG_Y));
	else if (pos == 'x' && move == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->s_right, \
				(data->p_x * IMG_X), (data->p_y * IMG_Y));
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->sprite, \
				(data->p_x * IMG_X), (data->p_y * IMG_Y));
}

void	ft_collect(t_data	*data)
{
	square_background(data->p_x, data->p_y, data);
	data->map->map[data->p_y][data->p_x] = '0';
	--data->total_c;
	if (data->total_c == 0)
	{
		square_background(data->e_x, data->e_y, data);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->exit, \
			(data->e_x * IMG_X), (data->e_y * IMG_Y));
	}
}

void	move_y(t_data	*data, char pos, int move)
{
	if (((pos == 'y' && data->map->map[data->p_y + move][data->p_x] != '1') \
		&& (pos == 'y' && data->map->map[data->p_y + move][data->p_x] != 'E')) \
		|| (pos == 'y' && data->map->map[data->p_y + move][data->p_x] == 'E' \
			&& data->total_c == 0))
		data->p_y += move;
}

void	move_x(t_data	*data, char pos, int move)
{
	if (((pos == 'x' && data->map->map[data->p_y][data->p_x + move] != '1') \
		&& (pos == 'x' && data->map->map[data->p_y][data->p_x + move] != 'E')) \
		|| (pos == 'x' && data->map->map[data->p_y][data->p_x + move] == 'E' \
			&& data->total_c == 0))
		data->p_x += move;
}

void	ft_move(t_data	*data, char pos, int move)
{
	if ((pos == 'y' && data->map->map[data->p_y + move][data->p_x] != '1') \
		|| (pos == 'x' && data->map->map[data->p_y][data->p_x + move] != '1'))
	{
		square_background(data->p_x, data->p_y, data);
		if (pos == 'y')
			move_y(data, pos, move);
		else
			move_x(data, pos, move);
		if (data->map->map[data->p_y][data->p_x] == 'C')
			ft_collect(data);
		parse_move(data, pos, move);
		if (data->enem->r_x)
			anim_enem(data);
		ft_printf("%d\n", ++data->counter);
		put_move(data);
	}
	mlx_do_sync(data->mlx);
}
