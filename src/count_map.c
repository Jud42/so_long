#include "so_long.h"

void	count_map(int fd, t_map	*map) // count line in map(fd)
{
	char	c;
	int	max;
	int	i_len;
	
	max = 0;
	map->x = 0;
	map->y = 0;
	i_len	= 0;
	while(1)
	{
		max = read(fd, &c, 1);
		if(max == 0)
			break;
		if(c != '\n' && i_len == 0)
			map->x++;	
		else if(c == '\n')
		{
			map->y++;
			i_len = 1;
		}
	}
}

void	window_x_y(char	**av, t_data	*data) //set width & height to window from map file #1
{
	int	fd = open(av[1], O_RDONLY);
	if(fd < 0)
	{
		perror("error\nMap_path not found\n");
		exit(EXIT_FAILURE);
	}
	if(ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
	{
		printf("error\nThe file is not .ber\n");
		exit(EXIT_FAILURE);
	}
	count_map(fd, data->map);
	data->width_x = data->map->x * IMG_X;
	data->height_y = data->map->y * IMG_Y + 32; /* + 32 space for move display*/
	close(fd);
}

void	tab_map(char	*file, t_map *p) //create the tab 2d and return it #2
{
	int	i;
	int	fd;
	
	i = 0;
	
	fd = open(file, O_RDONLY);
	if(!fd)
		return ;
	if(!p->map)
		p->map = NULL;
	while((p->map[i++] = get_next_line(fd))) //copy in **map line by line from fd
		;
	p->map[p->y] = 0; // set NULL end of array
}
