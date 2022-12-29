/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:50:01 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/29 12:43:22 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// includes
# include <stdlib.h>
# include <unistd.h>

// prototypes get_next_line.c
char	*get_next_line(int fd);

// prototypes get_next_line_utils.c
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, const char *s2);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_substr(const char *src, size_t len);
char	*gnl_strchr(const char *s, int c);

#endif