/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:24:39 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/09 18:25:00 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// count line in map(fd)
void	count_map(int fd, t_map	*map)
{
	char	c;
	int		max;
	int		i_len;

	max = 0;
	map->x = 0;
	map->y = 0;
	i_len = 0;
	while (1)
	{
		max = read(fd, &c, 1);
		if (max == 0)
			break ;
		if (c != '\n' && i_len == 0)
			map->x++;
		else if (c == '\n')
		{
			map->y++;
			i_len = 1;
		}
	}
}

//set width & height to window from map file #1
void	window_x_y(char	**av, t_data	*data)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap_path not found\n");
		exit(EXIT_FAILURE);
	}
	count_map(fd, data->map);
	data->width_x = data->map->x * IMG_X;
	data->height_y = data->map->y * IMG_Y;
	close(fd);
}

//create the tab 2d and return it #2
void	create_map(char	*file, t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return ;
	data->map->map = calloc(data->map->y + 1, sizeof(char *));
	if (!data->map->map)
	{
		perror("\nmalloc() Tab[][] failed\n");
		exit(EXIT_FAILURE);
	}
	while (i < data->map->y)
		data->map->map[i++] = get_next_line(fd);
	parse_map(data);
}
