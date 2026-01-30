/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:05:26 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 16:05:26 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	path_error(t_game *game, char **tmp, char *msg)
{
	free_map(tmp);
	tmp = NULL;
	game_error(game, msg);
}

static char	**dup_map(t_game *game)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!tmp)
		game_error(game, "Error\nMalloc fail");
	i = 0;
	while (i < game->height)
	{
		tmp[i] = ft_strdup(game->map[i]);
		if (!tmp[i])
		{
			tmp[i] = NULL;
			free_map(tmp);
			game_error(game, "Error\nMalloc fail");
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void	flood(t_flood *f, int y, int x)
{
	if (y < 0 || x < 0 || y >= f->game->height || x >= f->game->width)
		return ;
	if (f->map[y][x] == '1' || f->map[y][x] == 'V')
		return ;
	if (f->map[y][x] == 'C')
		f->found_c++;
	if (f->map[y][x] == 'E')
		f->found_e = 1;
	f->map[y][x] = 'V';
	flood(f, y - 1, x);
	flood(f, y + 1, x);
	flood(f, y, x - 1);
	flood(f, y, x + 1);
}

void	find_player(t_game *g, int *py, int *px)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			if (g->map[y][x] == 'P')
			{
				*py = y;
				*px = x;
				return ;
			}
			x++;
		}
		y++;
	}
	game_error(g, "Error\nPlayer not found");
}

void	check_path(t_game *game)
{
	t_flood	f;
	int		py;
	int		px;

	f.map = dup_map(game);
	f.game = game;
	f.found_c = 0;
	f.found_e = 0;
	find_player(game, &py, &px);
	flood(&f, py, px);
	if (f.found_c != game->collect || f.found_e != 1)
		path_error(game, f.map, "Error\nThere is no valid path");
	free_map(f.map);
}
