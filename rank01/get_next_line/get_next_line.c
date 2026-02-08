/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechavez <sechavez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:50:57 by sechavez          #+#    #+#             */
/*   Updated: 2025/12/17 14:19:49 by sechavez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes_read = 1;
	while (!gnl_chr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (0);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = gnl_join(stash, buffer);
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	new = 0;
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	new = malloc((gnl_len(stash) - i) + 1);
	if (!new)
		return (0);
	i++;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = read_and_stash(fd, stash);
	if (!stash || !stash[0])
		return (0);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}