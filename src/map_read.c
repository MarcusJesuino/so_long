/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:16:13 by masantos          #+#    #+#             */
/*   Updated: 2026/02/04 22:09:52 by masantos         ###   ########.fr       */
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

void parser(char *file, t_game *game)
{
	read_map(file, game);
	game->map = init_map(file, game->height, game->width);
	check_chars(game);
	check_elements(game);
	check_walls(game);
	check_path(game);
	}

void	read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	
	fd = open_map(file);
	line = get_next_line(fd);
	if (!line)
		cleanup_and_error("Map error!!!", game->map);
	game->width = ft_strlen_no_nl(line);	
	while (line)
	{
		if(game->width != ft_strlen_no_nl(line))
		{
			free(line);
			get_next_line(-1);
			close(fd);
			error("mapa não retangular");
		}
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

char **init_map(char *file, int height, int width)
{
	int		fd;
	int		ind_y;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0 )
		return(NULL);
	ind_y = 0;
	map = ft_calloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (ind_y < height)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map[ind_y] = malloc((width + 1) * sizeof(char));
		ft_memcpy(map[ind_y], line, (size_t)width);
		map[ind_y++][width] = '\0';
		free(line);
	}
	get_next_line(-1);
	close(fd);
	return(map);
}
