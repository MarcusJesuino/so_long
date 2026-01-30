/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:39:47 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 14:39:47 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_elements(t_game *game)
{
	int	i;
	int	j;

	game->player = 0;
	game->exit = 0;
	game->collect = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player++;
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collect++;
			j++;
		}
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->collect < 1)
		game_error(game, "Error\nElements invalid on the map");
}
