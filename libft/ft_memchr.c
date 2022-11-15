/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 10:30:53 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 15:26:22 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		if (*(unsigned char *)src == (unsigned char)c)
			return ((void *)src);
		src++;
	}
	return (0);
}

/* #include	<stdio.h>
#include	<string.h>
int	main ()
{
	printf("%s", ft_memchr(NULL, 'a', 5));
	// printf("%s", memchr(NULL, 'a', 5));
} */