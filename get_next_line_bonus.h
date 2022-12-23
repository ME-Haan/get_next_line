/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/15 11:50:01 by mhaan         #+#    #+#                 */
/*   Updated: 2022/12/23 14:12:48 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// includes
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// prototypes
char	*get_next_line(int fd);
char	*read_file(int fd, char *stash);
char	*get_lines(char *stash);
char	*update_stash(char *stash);

void	*gnl_memcpy(void *dst, void *src, size_t n);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(char *str);
char	*gnl_substr(char *src, size_t len);

#endif