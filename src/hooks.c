/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:31:19 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 23:31:19 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *g)
{
	destroy_game(g);
	exit(0);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		close_game(g);
	else if (keycode == 'w' || keycode == KEY_UP)
		try_move(g, -1, 0);
	else if (keycode == 's' || keycode == KEY_DOWN)
		try_move(g, 1, 0);
	else if (keycode == 'a' || keycode == KEY_LEFT)
		try_move(g, 0, -1);
	else if (keycode == 'd' || keycode == KEY_RIGHT)
		try_move(g, 0, 1);
	return (0);
}
