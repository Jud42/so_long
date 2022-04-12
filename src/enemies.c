/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:34:31 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 15:46:28 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_enem(t_data *data)
{
	++data->enem->count;
	if (data->enem->count == 2)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->enem->img_1, data->enem->r_x * 64, data->enem->r_y * 64);
	}
	else if (data->enem->count == 3)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->enem->img_2, data->enem->r_x * 64, data->enem->r_y * 64);
	}
	else if (data->enem->count == 4)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->enem->img_3, data->enem->r_x * 64, data->enem->r_y * 64);
	}
	else if (data->enem->count == 5)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
			data->enem->img_4, data->enem->r_x * 64, data->enem->r_y * 64);
		data->enem->count = 0;
	}
}
