/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:19:12 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 11:24:17 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* # include	<stdio.h>
# include	<string.h>
int	main(void)
{
	char *c = NULL;

	printf("ft: %lu\n", ft_strlen(c));
	printf("test: %lu\n", strlen(c));
} */
