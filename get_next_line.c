/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2023/01/13 13:20:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash);
static char	*get_line(char *str);
static char	*update_stash(char *str);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = gnl_strjoin(stash, "");
	if (!stash)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = update_stash(stash);
	return (line);
}

static char	*read_file(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), NULL);
		buff[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buff);
		if (!stash)
			return (NULL);
		if (gnl_strchr(buff, '\n'))
			break ;
	}
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*nl_pos;
	char	*line;

	nl_pos = gnl_strchr(stash, '\n');
	if (nl_pos)
		line = gnl_substr(stash, gnl_strlen(stash) - gnl_strlen(nl_pos) + 1);
	else
		line = gnl_substr(stash, gnl_strlen(stash));
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*nstash;
	char	*nl_pos;

	nl_pos = gnl_strchr(stash, '\n');
	if (!nl_pos)
		return (free(stash), NULL);
	nstash = gnl_substr(nl_pos + 1, gnl_strlen(nl_pos) - 1);
	if (!nstash)
		return (free(stash), NULL);
	return (free(stash), nstash);
}
