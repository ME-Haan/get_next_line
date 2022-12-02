/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/02 15:56:26 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*read_line(int fd, char *stash)
{
	char	*BUFF;
	size_t	bytes_read;
	char	*tmp;

	BUFF = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!BUFF)
		return (NULL);
	bytes_read = 1;
	str = gnl_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, BUFF, BUFFER_SIZE);
		BUFF[bytes_read] = '\0';
		tmp = gnl_strjoin(str, BUFF);
		if (!tmp)
			return (free(BUFF), free(str), NULL);
		free(str);
		str = tmp;
		if (gnl_strchr(str, '\n'))
			return (free(BUFF), free(tmp), str);
	}
	return (free(BUFF), free(tmp), str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	str = read_line(fd, stash);
	stash = gnl_strchr(str, '\n');
	if (stash)
	{
		str = gnl_substr(str, 0, gnl_strlen(str) - gnl_strlen(stash) + 1);
		stash++;
		return (str);
	}
	return (str);
}

#include <fcntl.h>
int	main(int argc, char *argv[])
{
	(void)argc;
	int	fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	printf("File:\n%s", str);
}