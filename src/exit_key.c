/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_close_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:24:15 by rmamison          #+#    #+#             */
/*   Updated: 2022/03/30 15:41:45 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_key(t_data	*data) //close to window if press esc
{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit (EXIT_SUCCESS);
		return (0);
}
