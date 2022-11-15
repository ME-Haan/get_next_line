/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:44:32 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/10 13:49:49 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*# include	<stdio.h>
# include	<ctype.h>
int	main(void)
{
	char c = '!';

	printf("ft: %i\n", ft_isascii(c));
	printf("test: %i", isascii(c));
}*/
