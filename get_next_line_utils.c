/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:53:10 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/07 17:58:55 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	const size_t	s1len = gnl_strlen(s1);
	const size_t	s2len = gnl_strlen(s2);
	char			*mem;

	mem = (char *)malloc(s1len + s2len + 1 * sizeof(char));
	if (!mem)
	{
		if (s1)
			free(s1);
		return (-1);
	}
	if (s1)
		gnl_memcpy(mem, s1, s1len);
	gnl_memcpy(mem + s1len, s2, s2len + 1);
	return (free(s1), mem);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	const char	*stmp = (const char *)src;
	char		*dtmp;

	if (!dst && !src)
		return (NULL);
	dtmp = (char *)dst;
	while (n-- > 0)
		dtmp[n] = stmp[n];
	return (dst);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (start > gnl_strlen(s))
	{
		len = 0;
		start = 0;
	}
	else if (len > (gnl_strlen(s) - start))
		len = gnl_strlen(s) - start;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (free(s), NULL);
	gnl_strlcpy(mem, s + start, len + 1);
	return (mem);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = gnl_strlen(src);
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

char	*gnl_strchr(const char *s, int c)
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
