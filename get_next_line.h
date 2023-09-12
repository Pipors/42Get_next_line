/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:46:42 by aatbir            #+#    #+#             */
/*   Updated: 2023/03/15 15:49:02 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *str, int c);
char	*read_file(int fd, char *reserve);
char	*gline(char *reserve);
char	*newres(char *reserve);
char	*get_next_line(int fd);

#endif
