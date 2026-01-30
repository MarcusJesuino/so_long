/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:23:43 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 23:23:43 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_to(t_game *g, int ny, int nx)
{
	g->map[g->py][g->px] = '0';
	g->map[ny][nx] = 'P';
	g->py = ny;
	g->px = nx;
	g->moves++;
	ft_printf("Moves: %d\n", g->moves);
}

static void	win_game(t_game *g)
{
	ft_printf("You win in %d moves!\n", g->moves + 1);
	close_game(g);
}

void	try_move(t_game *g, int dy, int dx)
{
	int		ny;
	int		nx;
	char	cell;

	ny = g->py + dy;
	nx = g->px + dx;
	cell = g->map[ny][nx];
	if (cell == '1')
		return ;
	if (cell == 'C')
		g->collect--;
	if (cell == 'E')
	{
		if (g->collect == 0)
			win_game(g);
		return ;
	}
	move_to(g, ny, nx);
	render_map(g);
}
