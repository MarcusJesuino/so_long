/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:35:41 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 13:35:41 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *game)
{
	if (!game)
		error("Error\nInvalid Game");
	if (!game->map)
		error("Error\nMapa not loaded");
	check_rectangle(game);
	check_walls(game);
	check_chars(game);
	check_elements(game);
	check_path(game);
}

