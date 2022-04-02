/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:13:31 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/01 13:46:26 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_tab(t_data	*data, t_map *map)
{
	data->total_c = 0;	
	map->y = 0;
	while(map->y < (data->height_y / IMG_Y - 1)) /* -1 for space display move*/
	{
		map->x = 0;
		while(map->x < (data->width_x / IMG_X))
		{
			if(map->map[map->y][map->x] == '1')
				put_element(data, "./gametiles/wall.xpm");
			else if(map->map[map->y][map->x] == 'C')
			{	
				put_element(data, "./gametiles/collect.xpm");
				data->total_c++;
			}
			else if(map->map[map->y][map->x] == 'E')
				put_element(data, "./gametiles/sprite/player.xpm");			
			else if(map->map[map->y][map->x] == 'P')
				put_player(data, "./gametiles/exit.xpm");
			map->x++;
		}
		map->y++;
	}
}
