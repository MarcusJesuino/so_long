/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:31:29 by masantos          #+#    #+#             */
/*   Updated: 2026/02/04 22:05:52 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**grow_map(char **old, int old_size)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (old_size + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	new[old_size] = NULL;
	new[old_size + 1] = NULL;
	return (new);
}

void	validate_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + (len - 4), ".ber", 4) != 0)
		error("Error\nFile need to be .ber");
}
