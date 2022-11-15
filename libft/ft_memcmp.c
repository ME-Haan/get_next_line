/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:43:13 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 15:28:35 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1 = s1;
	const unsigned char	*src2 = s2;
	size_t				i;

	i = 0;
	while (i++ < n)
	{
		if (src1[i - 1] != src2[i - 1])
			return (src1[i - 1] - src2[i - 1]);
	}
	return (0);
}

/* #include	<stdio.h>
#include	<string.h>
int	main ()
{
	// printf("%d", ft_memcmp(NULL, NULL, 5));
	printf("%d", memcmp("123", NULL, 5));
} */