/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/22 19:52:26 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash);
static char	*get_line(char *str);
static char	*update_stash(char *str);

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = gnl_strjoin("", "", 0);
		if (!stash)
			return (NULL);
	}
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
	char	*buff;
	int		bytes_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(stash), NULL);
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), free(buff), NULL);
		buff[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buff, 1);
		if (!stash)
			return (free(buff), NULL);
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
		line = gnl_substr(stash, gnl_strlen(stash) - gnl_strlen(nl_pos) + 1);
	else
		line = gnl_substr(stash, gnl_strlen(stash));
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*nstash;
	int		i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i])
	{
		nstash = gnl_substr(&stash[i], gnl_strlen(stash) - i);
		if (!nstash)
			return (free(stash), NULL);
	}
	else
		return (free(stash), NULL);
	return (free(stash), nstash);
}
