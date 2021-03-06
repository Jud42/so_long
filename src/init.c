/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:18:55 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 17:26:58 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(void *ptr_mlx, char *s, t_data *data)
{
	free(ptr_mlx);
	free_map(data);
	ft_printf("Error\n%s\n", s);
	exit(EXIT_FAILURE);
}

void	init_data_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_msg(data->mlx, "MLX_INIT_FAILED", data);
	data->mlx_win = mlx_new_window(data->mlx, data->width_x, \
			data->height_y, "so_long");
	if (!data->mlx_win)
		error_msg(data->mlx_win, "MLX_NEW_WINDOW_FAILED", data);
	data->img->mlx_img = mlx_new_image(data->mlx, data->width_x, \
			data->height_y);
	if (!data->img->mlx_img)
		error_msg(data->img->mlx_img, "MLX_NEW_IMAGE_FAILED", data);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, \
			&data->img->bpp, &data->img->line_lenght, &data->img->endian);
	if (!data->img->addr)
		error_msg(data->img->addr, "MLX_GET_DATA_ADDR_FAILED", data);
	init_img(data);
}

void	init_enemies(t_data	*data)
{
	int	width;
	int	height;

	data->enem->img_1 = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/enemies/img_1.xpm", &width, &height);
	data->enem->img_2 = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/enemies/img_2.xpm", &width, &height);
	data->enem->img_3 = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/enemies/img_3.xpm", &width, &height);
	data->enem->img_4 = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/enemies/img_4.xpm", &width, &height);
}

void	init_img(t_data *data)
{
	int	width;
	int	height;

	data->img->texture = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/texture.xpm", &width, &height);
	data->img->s_up = mlx_xpm_file_to_image(data->mlx, \
			SPRITE_UP, &width, &height);
	data->img->s_down = mlx_xpm_file_to_image(data->mlx, \
			SPRITE_DOWN, &width, &height);
	data->img->s_left = mlx_xpm_file_to_image(data->mlx, \
			SPRITE_LEFT, &width, &height);
	data->img->s_right = mlx_xpm_file_to_image(data->mlx, \
			SPRITE_RIGHT, &width, &height);
	data->img->exit = mlx_xpm_file_to_image(data->mlx, \
			"./gametiles/exit_open.xpm", &width, &height);
	init_enemies(data);
}
