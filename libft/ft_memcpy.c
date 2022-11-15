/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 16:54:29 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 15:34:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char		*stmp = (const char *)src;
	char			*dtmp;

	if (!dst && !src)
		return (0);
	dtmp = (char *)dst;
	while (n-- > 0)
		dtmp[n] = stmp[n];
	return (dst);
}

/* #include	<stdio.h>
#include	<string.h>
int	main(void)
{
	char *src = "123";
	char *dst = NULL;

	ft_memcpy(dst, src, 1);
	printf("ft_memcpy: %s\n", dst);

	char *dst2 = NULL;
	
	memcpy(dst2, src, 1);
	printf("memcpy: %s\n", dst2);
} */