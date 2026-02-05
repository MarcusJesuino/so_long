/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masantos <masantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:05 by masantos          #+#    #+#             */
/*   Updated: 2025/10/28 18:34:34 by masantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	free_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
	return ;
}



char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_stash(&stash);
		return (NULL);
	}
	bytes = 1;
	ft_bzero(&buffer, sizeof(buffer));
	while ((ft_strchr(stash, '\n') == NULL) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free_stash(&stash);
			return(0);
		}
		buffer[bytes] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free (tmp);
	}
	line = take_line(stash);
	tmp = stash;
	stash = get_remainder(tmp);
	free(tmp);
	if (bytes == 0)
		stash = NULL;
	return (line);
}
