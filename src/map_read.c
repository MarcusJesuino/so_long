/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:16:13 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 15:16:13 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	open_map(char *file)
{
	int	fd;

	validate_extension(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error\nThe map could not be opened");
	return (fd);
}

static char	**init_map(t_game *game)
{
	char	**map;

	game->height = 0;
	game->width = 0;
	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		error("Error\nMalloc fail");
	map[0] = NULL;
	return (map);
}

static void	append_line(t_game *game, char ***map, char *line, int fd)
{
	char	**old;

	old = *map;
	trim_newline(line);
	if (game->height == 0)
	{
		game->width = (int)ft_strlen(line);
		if (game->width == 0)
			cleanup_and_error("Error\nInvalid map", fd, old, line);
	}
	*map = grow_map(*map, game->height);
	if (!(*map))
		cleanup_and_error("Error\nMalloc fail", fd, old, line);
	(*map)[game->height++] = line;
}

char	**read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open_map(file);
	map = init_map(game);
	line = get_next_line(fd);
	if (!line)
		cleanup_and_error("Error\nEmpty map", fd, map, NULL);
	while (line)
	{
		append_line(game, &map, line, fd);
		line = get_next_line(fd);
	}
	map[game->height] = NULL;
	close(fd);
	game->map = map;
	return (map);
}
