/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:18:41 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 14:18:41 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			game_error(game, "Error\nThe map is not enclosed by walls");
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			game_error(game, "Error\nThe map is not enclosed by walls");
		i++;
	}
}
