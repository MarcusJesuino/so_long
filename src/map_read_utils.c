/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:31:29 by masantos          #+#    #+#             */
/*   Updated: 2026/01/29 15:31:29 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*trim_newline(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

char	**grow_map(char **old, int old_size)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (old_size + 2));
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
	free(old);
	return (new);
}

void	validate_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + (len - 4), ".ber", 4) != 0)
		error("Error\nFile need to be .ber");
}
