/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:22:48 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 14:22:48 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_rectangle(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->width;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->map[i]) != len)
			game_error(game, "Error\nNot a rectangular map");
		i++;
	}
}
