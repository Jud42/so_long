/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:29:16 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/01 14:08:29 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_move(t_data	*data, char pos, int move)
{
	(void) pos;
	(void) move;
	/*dans cette fonction je vais analyser la direction et push image qui correspond a ce dernier*/
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img->sprite, (data->p_x * IMG_X), (data->p_y * IMG_Y + 32)); /* + 32 display move*/

}

void	ft_collect(t_data	*data)
{
		square_background(data, BACKGR_PIXEL);
		data->map->map[data->p_y][data->p_x] = '0';
		--data->total_c;
		if(data->total_c == 0)
		{
			//I need to insert a new image for exit here (ex : open door)
			printf("you can leave rightnow\n");
		}
}
void	ft_move(t_data	*data, char pos, int move)
{
  	if((pos == 'y' && data->map->map[data->p_y + move][data->p_x] != '1') ||
			 (pos == 'x' && data->map->map[data->p_y][data->p_x + move] != '1'))
				square_background(data, BACKGR_PIXEL);
	if((pos == 'y' && data->map->map[data->p_y + move][data->p_x] != '1' ) &&
			(pos == 'y' && data->map->map[data->p_y + move][data->p_x] != 'E'))
				data->p_y += move;
	else if((pos == 'x' && data->map->map[data->p_y][data->p_x + move] != '1') &&
			(pos == 'x' && data->map->map[data->p_y][data->p_x + move] != 'E'))
				data->p_x += move;
	else if((pos == 'y' && data->map->map[data->p_y + move][data->p_x] == 'E' && 
		data->total_c == 0) || (pos == 'x' && data->map->map[data->p_y][data->p_x + move] == 'E' 
				&& data->total_c == 0)){
				if(pos == 'y')
					data->p_y += move;
				else
					data->p_x += move;
	}
	if(data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	parse_move(data, pos, move);
	mlx_do_sync(data->mlx);
}

int	key_hook_event(int	keycode, t_data	*data)
{
	if(keycode == 53)
		exit_key(data);
	if(keycode == UP)
		ft_move(data, 'y', -1);
	else if(keycode == DOWN)
		ft_move(data, 'y', 1);
	else if(keycode == LEFT)
		ft_move(data, 'x', -1);
	else if(keycode == RIGHT)
		ft_move(data, 'x', 1);
	if(data->map->map[data->p_y][data->p_x] == 'E')
		printf("finish game\n");
	return (0);
}
