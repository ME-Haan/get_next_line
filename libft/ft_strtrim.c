/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:51:18 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/27 11:53:47 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	nstr = ft_substr(s1, start, end - start + 1);
	return (nstr);
}

/* #include	<stdio.h>
int	main ()
{
	printf("%s", ft_strtrim(NULL, NULL));
} */