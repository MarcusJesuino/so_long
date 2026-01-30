/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:29:49 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 13:29:49 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/mlx/minilibx-linux/mlx.h"

# define TILE 64

# define FLOOR_PATH "./sprites/floor.xpm"
# define WALL_PATH "./sprites/wall.xpm"
# define PLAYER_PATH "./sprites/player.xpm"
# define EXIT_PATH "./sprites/exit.xpm"
# define COLLECT_PATH "./sprites/collect.xpm"

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collect;

	void	*mlx;
	void	*win;

	t_img	floor_img;
	t_img	wall_img;
	t_img	player_img;
	t_img	exit_img;
	t_img	collect_img;

	int		px;
	int		py;
	int		moves;
}	t_game;

typedef struct s_flood
{
	char	**map;
	t_game	*game;
	int		found_c;
	int		found_e;
}	t_flood;

void	error(char *msg);
void	free_map(char **map);
void	cleanup_and_error(char *msg, int fd, char **map, char *line);
void	game_error(t_game *game, char *msg);

void	check_map(t_game *game);
void	check_rectangle(t_game *game);
void	check_walls(t_game *game);
void	check_elements(t_game *game);
void	check_chars(t_game *game);
void	check_path(t_game *game);

char	**read_map(char *file, t_game *game);
void	validate_extension(char *file);
char	*trim_newline(char *line);
char	**grow_map(char **old, int old_size);
void	find_player(t_game *g, int *py, int *px);

void	mlx_init_game(t_game *g);
void	try_move(t_game *g, int dy, int dx);
int		key_hook(int keycode, t_game *g);
int		close_game(t_game *g);
void	destroy_game(t_game *g);

#endif
