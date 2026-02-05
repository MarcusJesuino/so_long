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

static void	load_one(t_game *g, void **img, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(g->mlx, path, &w, &h);
	if (!*img)
	{
		clean_controler(g);
		error("Fail to load image.");
	}
}

void	load_sprites(t_game *g)
{
	load_one(g, &g->floor_img, FLOOR_PATH);
	load_one(g, &g->wall_img, WALL_PATH);
	load_one(g, &g->player_img, PLAYER_PATH);
	load_one(g, &g->exit_img, EXIT_PATH);
	load_one(g, &g->collect_img, COLLECT_PATH);
}
