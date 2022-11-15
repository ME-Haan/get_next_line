/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:22:18 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/10 13:48:43 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* #include <stdio.h>
#include <string.h>
int main(void)
{
	int i = 0;
	
	char str[50] = "0123456789";
    printf("Before bzero(): %s\n", str);
	bzero(str, 5);
    while (i < 10)
	{
		write(1, &str[i], 1);
		i++;
	}

	write(1, "\n", 1);
	i = 0;
    
	char str2[50] = "0123456789";
    printf("Before ft_bzero(): %s\n", str2);
	ft_bzero(str2, 5);
    while (i < 10)
	{
		write(1, &str2[i], 1);
		i++;
	}
} */