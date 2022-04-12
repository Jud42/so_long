/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmamison <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:55:20 by rmamison          #+#    #+#             */
/*   Updated: 2022/04/12 17:32:15 by rmamison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	t_img	img;
	t_enem	enem;

	ft_parse_arg(argc, argv);
	data.map = &map;
	data.img = &img;
	data.enem = &enem;
	window_x_y(argv, &data);
	create_map(argv[1], &data);
	init_data_mlx(&data);
	render_event(&data);
	free(data.mlx);
	return (0);
}
