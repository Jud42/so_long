/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_close_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:24:15 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/08 12:26:43 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//close to window if press esc
int	exit_key(int keycode, t_data	*data)
{
	if (keycode == 53)
	{	
		ft_end_game(data);
		exit (0);
	}
	return (0);
}

//close to window with mouse (click x)
int	mouse_exit(t_data	*data)
{
	ft_end_game(data);
	exit (0);
	return (0);
}
