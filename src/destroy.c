/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:48:35 by masantos          #+#    #+#             */
/*   Updated: 2026/02/04 19:59:21 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_img(t_game *g, void *img)
{
		mlx_destroy_image(g->mlx, img);
		img = NULL;
}

void	destroy_game(t_game *g)
{
	destroy_img(g, g->exit_img);
	destroy_img(g, g->floor_img);
	destroy_img(g, g->wall_img);
	destroy_img(g, g->player_img);
	destroy_img(g, g->collect_img);
}

void	clean_controler(t_game *g)
{
	destroy_game(g);
	free_map(g->map);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
}