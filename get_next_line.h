/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:50:01 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/08 12:10:51 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 255
# endif

// includes
# include <stdlib.h>
# include <unistd.h>

// prototypes
char	*get_next_line(int fd);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	gnl_strlen(const char *str);
char	*gnl_substr(char *s, unsigned int start, size_t len);

#endif