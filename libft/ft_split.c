/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:24:46 by mhaan         #+#    #+#                 */
/*   Updated: 2022/11/15 11:18:26 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	count_splits(char const *s, char c);
static void		free_arr(char **arr, size_t i);
static int		fill_array(char const *s, char c, const size_t cnt, char **arr);

static size_t	count_splits(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	free_arr(char **arr, size_t i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

static int	fill_array(char const *s, char c, const size_t cnt, char **arr)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < cnt)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		arr[i] = ft_substr(s, start, end - start);
		if (!arr[i])
			return (free_arr(arr, i), 1);
		i++;
		start = end;
	}
	return (arr[i] = 0, 0);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	const size_t	count = count_splits(s, c);

	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (0);
	if (fill_array(s, c, count, arr) == 0)
		return (arr);
	return (0);
}

/* #include	"stdio.h"
int	main(void)
{
	// char str[] = "abc---efg--erga-adsgdgs----dsgas-da";
	// char delim = '-';

	char **arr = ft_split("hello!", ' ');

	while (*arr)
	{
		printf("%s", *arr);
		arr++;
	}
} */
