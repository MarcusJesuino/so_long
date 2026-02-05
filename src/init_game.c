/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:27:41 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 22:27:41 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	find_player_pos(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'P')
			{
				g->py = y;
				g->px = x;
				return ;
			}
			x++;
		}
		y++;
	}
	game_error(g, "Error\nPlayer not found");
}

void	initialize_game(t_game *g)
{
	g->moves = 0;
	find_player_pos(g);
}
