/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:14:24 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/17 10:23:48 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	size_t			i;

	i = 0;
	while (src[i] && i < (dstsize - 1) && dstsize != 0)
	{
			dst[i] = src[i];
			i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (srclen);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "Dit is een testzin!";
	char buff[19];

	printf("Length: %lu, Buff: %s\n", strlcpy(buff, str, 3), buff);
	return (0);
} */