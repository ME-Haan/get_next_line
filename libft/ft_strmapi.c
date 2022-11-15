/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 10:39:53 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/21 12:03:25 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*nstr;

	i = 0;
	nstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!nstr)
		return (0);
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}
