/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 12:47:14 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/21 15:28:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;
	char	*ptr;

	i = 0;
	nlen = ft_strlen(needle);
	ptr = (char *)haystack;
	if (nlen == 0)
		return (ptr);
	if (ft_strlen(haystack) == 0 || nlen > len)
		return (0);
	while (i <= len - nlen && ptr[i])
	{	
		if (ft_strncmp(&ptr[i], needle, nlen) == 0)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
