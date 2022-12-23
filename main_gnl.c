/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_gnl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 12:06:46 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/22 18:20:30 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	int fd;
	char *line;

	// fd = open(argv[1], O_RDONLY);
	fd = open("error-test.txt", O_RDONLY);
	printf("File:\n");
	int i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		i++;
	}

	// char *nstr;
	// char *line = NULL;

	// nstr = gnl_strjoin(NULL, line);

	// printf("%s", nstr);
	// printf("%s", gnl_strchr(str, '\n'));
}