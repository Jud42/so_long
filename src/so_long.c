/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:55:20 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/01 12:25:10 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int	argc, char	**argv)
{
	t_data data;
	t_map	map;
	t_img	img;
	if(argc != 2)
		return	(-1);

	data.map = &map;
	data.img = &img;	
	window_x_y(argv, &data);
	map.map = (char **)calloc(map.y + 1, sizeof(char	*));
	if(!map.map)
	{
		perror("\nTab Memory Allocations failed\n");
		exit(EXIT_FAILURE);
	}
	printf("width = %d\nheight = %d\n", data.width_x, data.height_y);
	tab_map(argv[1], &map);
	
	data.mlx = mlx_init();
	//if(data.mlx == NULL)
	//	return	(MLX_ERROR);
	
	data.mlx_win = mlx_new_window(data.mlx, data.width_x, data.height_y, "so_long");
/*	if(data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (MLX_ERROR);
	}*/
	
	img.mlx_img = mlx_new_image(data.mlx, data.width_x, data.height_y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_lenght, &img.endian);
	//init_img(&data, &img);
	rander(&data);
	//read_tab(&data, &p);
	//mlx_loop_hook(data.mlx, &rander, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	return (0);
}
