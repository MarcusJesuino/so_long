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

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*free_stash(char *stash, char *buffer)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*ptr;
	size_t			i;

	if (size == 0 || count == 0)
		return (malloc(1));
	if (size && count > (size_t)-1 / size)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)mem;
	while (i < count * size)
		ptr[i++] = (unsigned char) '\0';
	return (mem);
}

static char	*get_buffer(char *stash, int fd)
{
	char	*tmp;
	char	*buffer;
	ssize_t	bytes_read;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash || !buffer)
		return (free_stash(stash, buffer));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_stash(stash, buffer));
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (free_stash(stash, buffer));
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = get_buffer(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = get_nl(stash[fd]);
	tmp = stash[fd];
	stash[fd] = get_remainder(stash[fd]);
	free(tmp);
	return (line);
}
