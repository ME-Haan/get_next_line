/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:48:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/15 14:43:29 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include	"get_next_line.h"

char	*get_next_line(int fd)
{
	static ssize_t BUFFER_SIZE = 0;

	while (read(fd, BUFFER_SIZE, 1) > 0)

}

