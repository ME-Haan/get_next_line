/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 13:50:33 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/10 13:49:37 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* # include	<stdio.h>
# include	<ctype.h>
int	main(void)
{
	char c = '1';
	
	printf("ft: %i", ft_isalpha(c));
	printf("test: %i", isalpha(c));
} */
