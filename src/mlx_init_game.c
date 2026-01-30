/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:45:33 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 17:45:33 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_init_game(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		game_error(g, "Error\nmlx_init fail");
	g->win = mlx_new_window(g->mlx, g->width * TILE,
			g->height * TILE, "so_long");
	if (!g->win)
		game_error(g, "Error\nmlx_new_window fail");
}
