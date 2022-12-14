/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/14 18:29:36 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*read_file(int fd, char *stash);
// static char	*get_line_update_stash(char *stash, char **stash_ptr);
static char	*get_line(char *str);
static char	*update_stash(char *str);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (!line)
		return (free(stash), NULL);
	stash = update_stash(stash);
	// if (line[0] == '\0')
	// 	return (free(stash), stash = NULL, free(line), NULL);
	return (line);
}

static char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	if (!stash)
	{
		stash = malloc(1 * sizeof(char *));
		stash[0] = '\0';
	}
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), NULL);
		buff[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buff, 1);
		// if (!stash)
		// 	return (free(buff), NULL);
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
		if (*(nl_pos + 1))
			line = gnl_substr(stash, 0, gnl_strlen(stash) - gnl_strlen(nl_pos) + 1);
		else
			line = gnl_substr(stash, 0, gnl_strlen(stash) - gnl_strlen(nl_pos) + 2);
		if (!line)
			return (NULL);
		return (line);
	}
	else
		return (line = gnl_strjoin(stash, "", 0), line);
}

static char	*update_stash(char *stash)
{
	char	*nl_pos;
	char	*new_stash;

	nl_pos = gnl_strchr(stash, '\n');
	if (nl_pos && *(nl_pos + 1))
	{
		new_stash = gnl_substr(nl_pos, 1, gnl_strlen(nl_pos) - 1);
		if (!new_stash)
			return (free(stash), NULL);
		return (free(stash), new_stash);
	}
	return (free(stash), NULL);
}

// char	*get_next_line(int fd)
// {
// 	static char	*stash = NULL;
// 	char		*str;
// 	char		*tmp;

// 	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
// 		return (NULL);
// 	if (stash && gnl_strchr(stash, '\n'))
// 		tmp = gnl_strjoin(stash, "");
// 	else
// 		tmp = read_file(fd, stash);
// 	if (!tmp)
// 		return (free(stash), NULL);
// 	stash = set_stash(tmp);
// 	str = get_line(tmp);
// 	if (gnl_strlen(str) == 0 && str)
// 		return (free(stash), free(str), NULL);
// 	else if (gnl_strlen(str) == 0 && !str)
// 		return (free(stash), NULL);
// 	return (str);
// }

// static char	*read_file(int fd, char *stash)
// {
// 	char	*buff;
// 	// char	*str;
// 	// char	*tmp;
// 	int		bytes_read;

// 	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buff)
// 		return (NULL);
// 	// str = gnl_strjoin(stash, "");
// 	bytes_read = read(fd, buff, BUFFER_SIZE);
// 	// while (!gnl_strchr(str, '\n') && bytes_read > 0)
// 	while (!gnl_strchr(stash, '\n') && bytes_read > 0)
// 	{
// 		buff[bytes_read] = '\0';
// 		// tmp = gnl_strjoin(stash, buff);
// 		stash = gnl_strjoin(stash, buff);
// 		// if (!tmp)
// 		if (!stash)
// 			return (free(buff), NULL);
// 		// str = gnl_strjoin(tmp, "");
// 		// if (gnl_strchr(str, '\n'))
// 		// 	return (free(buff), str);
// 		bytes_read = read(fd, buff, BUFFER_SIZE);
// 	}
// 	if (bytes_read < 0 || (!stash && bytes_read == 0))
// 		return (free(buff), free(str), free(stash), NULL);
// 		// return (free(buff), free(str), free(stash), NULL);
// 	return (free(buff), str);
// }

// static char	*get_line_update_stash(char *stash, char **stash_ptr)
// {
// 	char	*nl_pos = gnl_strchr(stash, '\n');
// 	char	*line;
// 	char	*new_stash;

// 	nl_pos = gnl_strchr(stash, '\n');
// 	if (nl_pos)
// 	{
// 		line = gnl_substr(stash, 0, gnl_strlen(stash) - gnl_strlen(nl_pos) + 1);
// 		if (!line)
// 			return (free(stash), NULL);
// 		new_stash = gnl_substr(nl_pos, 1, gnl_strlen(nl_pos) - 1);
// 		if (!new_stash)
// 			return (free(stash), free(line), NULL);
// 		free(stash);
// 		*stash_ptr = gnl_strjoin(new_stash, "");
// 		return (line);
// 	}
// 	else
// 		return (line = gnl_strjoin(stash, ""), line);
// }