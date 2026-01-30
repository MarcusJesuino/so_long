/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:14:24 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 23:14:24 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			put_tile(g, g->floor_img.ptr, x, y);
			if (g->map[y][x] == '1')
				put_tile(g, g->wall_img.ptr, x, y);
			else if (g->map[y][x] == 'C')
				put_tile(g, g->collect_img.ptr, x, y);
			else if (g->map[y][x] == 'E')
				put_tile(g, g->exit_img.ptr, x, y);
			else if (g->map[y][x] == 'P')
				put_tile(g, g->player_img.ptr, x, y);
			x++;
		}
		y++;
	}
}
