/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/28 16:47:20 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>


char	*get_next_line(int fd)
{
	// static char	*stash;
	char		*BUFF;
	char		*str;
	char		*tmp;
	ssize_t		bytes_read;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	BUFF = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!BUFF)
		return (NULL);
	bytes_read = 1;
	len = 0;
	str = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, BUFF, BUFFER_SIZE);
		len += bytes_read;
		tmp = ft_strjoin(str, BUFF);
		if (!tmp)
			return (free (str), NULL);
		free(str);
		str = tmp;
	}
	str[len] = '\0';
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