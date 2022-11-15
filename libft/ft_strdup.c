/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:41:15 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/15 14:02:17 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_memcpy(mem, s1, ft_strlen(s1) + 1);
	return ((char *)mem);
}
