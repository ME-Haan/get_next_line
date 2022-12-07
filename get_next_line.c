/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/07 18:11:50 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*set_stash(char *str, char *stash)
{

}

static char	*get_line(char *str, char *stash)
{

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
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (tmp)
			free(tmp);
		tmp = gnl_strjoin(str, buff);
		if (!tmp)
			return (free(buff), free(str), NULL);
		if (str)
			free(str);
		str = tmp;
		if (gnl_strchr(str, '\n'))
			return (free(buff), free(tmp), str);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buff), free(tmp), free(str), NULL);
	return (free(buff), free(tmp), str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_file(fd, stash);
	if (!tmp)
		return (NULL);
	str = get_line(tmp);
	stash = set_stash(str, tmp);




	if (*stash)
	{
		stash++;
		str = gnl_substr(tmp, 0, gnl_strlen(tmp) - gnl_strlen(stash));
		if (!str)
			return (free(tmp), NULL);
		return (free(tmp), str);
	}
	str = tmp;
	return (free(tmp), str);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	(void) argc;
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	printf("File:\n");
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("test\n");
		printf("%s", str);
	}
}