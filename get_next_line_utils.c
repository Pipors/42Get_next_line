/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:02:58 by aatbir            #+#    #+#             */
/*   Updated: 2023/01/14 23:56:20 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		size;

	if (!s1)
		s1 = ft_strdup("");
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[size] = '\0';
	free(s1);
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char	*allocs;
	int		i;

	allocs = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!allocs)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		allocs[i] = s1[i];
		i++;
	}
	allocs[i] = '\0';
	return (allocs);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != (char )c)
		i++;
	if (str[i] == (char )c)
		return (&str[i]);
	return (NULL);
}
