/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: martin <martin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/09 15:50:55 by martin        #+#    #+#                 */
/*   Updated: 2022/10/14 17:07:13 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last);
}

/* #include	<stdio.h>
#include	<string.h>
int	main(void)
{
	char	*str =  "In deze zin wil ik '0' vinden!";
	char	to_find = 0;

	printf("strchr: %s\n", strrchr(str, to_find));
	printf("ft_strchr: %s\n", ft_strrchr(str, to_find));
} */