/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 15:03:01 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 15:39:18 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s = (const char *)src;
	char		*d;
	size_t		i;

	d = (char *)dst;
	if (!s && !d)
		return (0);
	if (dst > src)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

/*#include	<stdio.h>
#include	<string.h>
int main(void)
{
	char *csrc = "123";
	memmove(NULL, csrc, 0);
	printf("%s\n", csrc);
	
	char *csrc2 = "123";
	ft_memmove(NULL, csrc2, 0);
	printf("%s\n", csrc2);
}*/