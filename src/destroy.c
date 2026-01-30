/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:48:35 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 23:48:35 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_img(t_game *g, t_img *img)
{
	if (img->ptr)
	{
		mlx_destroy_image(g->mlx, img->ptr);
		img->ptr = NULL;
	}
}

void	destroy_game(t_game *g)
{
	if (!g)
		return ;
	if (g->mlx)
	{
		destroy_img(g, &g->floor);
		destroy_img(g, &g->wall);
		destroy_img(g, &g->player_img);
		destroy_img(g, &g->exit_img);
		destroy_img(g, &g->collect_img);
		if (g->win)
			mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
		g->win = NULL;
	}
	if (g->map)
		free_map(g->map);
	g->map = NULL;
}
