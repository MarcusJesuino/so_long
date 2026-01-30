/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:39:18 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 15:39:18 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	game_error(t_game *game, char *msg)
{
	if (game && game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	error(msg);
}

void	cleanup_and_error(char *msg, int fd, char **map, char *line)
{
	if (line)
		free(line);
	if (map)
		free_map(map);
	if (fd >= 0)
		close(fd);
	error(msg);
}
