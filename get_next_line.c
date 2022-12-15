/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/15 18:32:13 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*read_file(int fd, char *stash);
static char	*get_line(char *str);
static char	*update_stash(char *str);

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}

static char	*read_file(int fd, char *stash)
{
	char	*buff;
	// char	buff[BUFFER_SIZE + 1];
	int		bytes_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			// return (free(stash), NULL);
			return (free(stash), free(buff), NULL);
		buff[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buff);
	}
	return (free(buff), stash);
}

static char	*get_line(char *stash)
{
	char	*nl_pos;
	char	*line;

	if (!stash[0])
		return (NULL);
	nl_pos = gnl_strchr(stash, '\n');
	if (nl_pos)
	{
		line = gnl_substr(stash, 0, gnl_strlen(stash) - gnl_strlen(nl_pos) + 1);
		return (line);
	}
	else
		return (line = gnl_substr(stash, 0, gnl_strlen(stash) + 1), line);
}

static char	*update_stash(char *stash)
{
	char	*pos;
	char	*nstash;

	pos = gnl_strchr(stash, '\n');
	if (pos)
	{
		nstash = gnl_substr(pos, 1, gnl_strlen(pos));
		return (free(stash), nstash);
	}
	return (free(stash), NULL);
}
