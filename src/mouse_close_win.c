/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_close_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:25:51 by rmamison          #+#    #+#             */
/*   Updated: 2022/03/08 18:34:58 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	mouse_exit(t_data	*data) //close to window with mouse (click x)
{
	data = (void*)0;
	exit (0);
	return (0);
}
