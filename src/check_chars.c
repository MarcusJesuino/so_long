/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:22:08 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 14:22:08 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C')
				game_error(game, "Error\nCaracter invalid on the map");
			j++;
		}
		i++;
	}
}
