/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/08 16:52:40 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash);
static char	*get_line(char *str);
static char	*set_stash(char *str, char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (gnl_strchr(stash, '\n'))
		tmp = gnl_strjoin(stash, "");
	else
		tmp = read_file(fd, stash);
	if (!tmp)
		return (free(stash), NULL);
	str = get_line(tmp);
	if (!str)
		return (free(stash), free(tmp), NULL);
	stash = set_stash(str, stash);
	return (free(tmp), str);
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
			return (free(buff), free(str), NULL);
		str = gnl_strjoin(tmp, "");
		if (gnl_strchr(str, '\n'))
			return (free(buff), str);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buff), free(str), NULL);
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
			return (NULL);
		return (line);
	}
	else
		return (line = str, line);
}

static char	*set_stash(char *str, char *stash)
{
	char	*nl_pos;

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
