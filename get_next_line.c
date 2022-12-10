/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/10 16:57:36 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*read_file(int fd, char *stash);
static char	*get_line(char *str);
static char	*set_stash(char *str);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;
	char		*tmp;
	char		*buff[0];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	if (stash && gnl_strchr(stash, '\n'))
		tmp = gnl_strjoin(stash, "");
	else
		tmp = read_file(fd, stash);
	if (!tmp)
		return (free(stash), NULL);
	stash = set_stash(tmp);
	str = get_line(tmp);
	if (gnl_strlen(str) == 0 && str)
		return (free(stash), free(str), NULL);
	else if (gnl_strlen(str) == 0 && !str)
		return (free(stash), NULL);
	return (str);
}

static char	*read_file(int fd, char *stash)
{
	char	*buff;
	char	*str;
	char	*tmp;
	size_t	bytes_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	str = gnl_strjoin(stash, "");
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		tmp = gnl_strjoin(str, buff);
		if (!tmp)
			return (free(buff), NULL);
		str = gnl_strjoin(tmp, "");
		if (gnl_strchr(str, '\n'))
			return (free(buff), str);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buff), free(str), free(stash), NULL);
	return (free(buff), str);
}

static char	*get_line(char *str)
{
	const char	*pos = gnl_strchr(str, '\n');
	char		*line;

	if (pos)
	{
		line = gnl_substr(str, 0, gnl_strlen(str) - gnl_strlen(pos) + 1);
		if (!line)
			return (free(str), NULL);
		return (free(str), line);
	}
	else
		return (line = gnl_strjoin(str, ""), line);
}

static char	*set_stash(char *str)
{
	char	*nl_pos;
	char	*stash;

	nl_pos = gnl_strchr(str, '\n');
	if (nl_pos)
	{
		stash = gnl_substr(nl_pos, 1, gnl_strlen(nl_pos) - 1);
		if (!stash)
			return (NULL);
		return (stash);
	}
	return (NULL);
}
