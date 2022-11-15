/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:14:33 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/10 13:49:55 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* # include	<stdio.h>
# include	<ctype.h>
int	main(void)
{
	char c = '1';

	printf("ft: %i\n", ft_isdigit(c));
	printf("test: %i", isdigit(c));
} */
