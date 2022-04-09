/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:13:31 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/09 18:24:51 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_read(t_data *data, t_map *map)
{
	if (map->map[map->y][map->x] == 'E')
	{
		data->e_y = map->y;
		data->e_x = map->x;
	}
}

void	read_map(t_data	*data, t_map *map)
{
	data->counter = 0;
	map->y = 0;
	while (map->y < (data->height_y / IMG_Y))
	{
		map->x = 0;
		while (map->x < (data->width_x / IMG_X))
		{
			if (map->map[map->y][map->x] == '1')
				put_element(data, "./gametiles/wall.xpm");
			else if (map->map[map->y][map->x] == 'C')
				put_element(data, "./gametiles/collect.xpm");
			else if (map->map[map->y][map->x] == 'E')
				put_element(data, "./gametiles/exit_close.xpm");
			else if (map->map[map->y][map->x] == 'P')
				put_player(data, "./gametiles/player.xpm");
			help_read(data, map);
			map->x++;
		}
		map->y++;
	}
}
