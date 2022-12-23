/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:53:10 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/23 16:58:58 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char			*mem;
	const size_t	s1len = gnl_strlen(s1);
	const size_t	s2len = gnl_strlen(s2);

	mem = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!mem)
		return (free(s1), NULL);
	gnl_memcpy(mem, s1, s1len);
	gnl_memcpy(mem + s1len, s2, s2len + 1);
	return (free(s1), mem);
}

void	*gnl_memcpy(void *dst, void *src, size_t n)
{
	const char	*stmp = (const char *)src;
	char		*dtmp;

	if (!dst && !src)
		return (NULL);
	dtmp = (char *)dst;
	while (n-- > 0)
		dtmp[n] = stmp[n];
	return (dtmp);
}

char	*gnl_substr(char *src, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	srclen;

	srclen = gnl_strlen(src);
	if (!srclen && !len)
		return (NULL);
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
			mem[i] = src[i];
			i++;
	}
	mem[i] = '\0';
	return (mem);
}

char	*gnl_strchr(const char *s, int c)
{
	char	*nstr;

	nstr = (char *)s;
	while (*nstr && *nstr != (char)c)
		nstr++;
	if (*nstr == (char)c)
		return (nstr);
	return (0);
}
