/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:13:21 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 23:13:21 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_one(t_game *g, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(g->mlx, path, &img->w, &img->h);
	if (!img->ptr)
		game_error(g, "Error\nFail to load sprite");
}

void	load_sprites(t_game *g)
{
	load_one(g, &g->floor, FLOOR_PATH);
	load_one(g, &g->wall, WALL_PATH);
	load_one(g, &g->player_img, PLAYER_PATH);
	load_one(g, &g->exit_img, EXIT_PATH);
	load_one(g, &g->collect_img, COLLECT_PATH);
}
