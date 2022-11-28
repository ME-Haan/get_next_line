/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:53:10 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/28 16:53:16 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1len = ft_strlen(s1);
	const size_t	s2len = ft_strlen(s2);
	char			*mem;

	mem = (char *)malloc(s1len + s2len + 1 * sizeof(char));
	if (!mem)
		return (0);
	ft_memcpy(mem, s1, s1len);
	ft_memcpy(mem + s1len, s2, s2len + 1);
	return (mem);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*stmp = (const char *)src;
	char		*dtmp;

	if (!dst && !src)
		return (0);
	dtmp = (char *)dst;
	while (n-- > 0)
		dtmp[n] = stmp[n];
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (start > ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	size_t			i;

	i = 0;
	while (src[i] && i < (dstsize - 1) && dstsize != 0)
	{
			dst[i] = src[i];
			i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_memcpy(mem, s1, ft_strlen(s1) + 1);
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}