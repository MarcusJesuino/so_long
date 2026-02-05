/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:27:27 by masantos          #+#    #+#             */
/*   Updated: 2026/02/04 20:00:53 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
		error("Error\nUse: ./so_long mapa.ber");
	g.width = 0;
	g.height = 0;
	parser(av[1], &g);
	initialize_game(&g);
	mlx_init_game(&g);
	load_sprites(&g);
	render_map(&g);
	mlx_hook(g.win, 2, 1, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_game, &g);
	mlx_loop(g.mlx);
	clean_controler(&g);
	return (0);
}
