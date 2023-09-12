/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:58:37 by aatbir            #+#    #+#             */
/*   Updated: 2023/03/15 16:30:28 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *reserve)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		buffer[r] = '\0';
		reserve = ft_strjoin(reserve, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*gline(char *reserve)
{
	char	*line;
	int		i;

	if (*reserve == 0)
		return (NULL);
	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*newres(char *reserve)
{
	int		i;
	int		j;
	char	*new_res;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	new_res = malloc((ft_strlen(reserve) - i + 1) * sizeof(char));
	i++;
	if (!new_res)
		return (NULL);
	j = 0;
	while (reserve[i])
		new_res[j++] = reserve[i++];
	free(reserve);
	new_res[j] = '\0';
	return (new_res);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = read_file(fd, reserve);
	if (!reserve)
		return (NULL);
	line = gline(reserve);
	reserve = newres(reserve);
	return (line);
}

/*int main()
{
	int fd = open("test.txt", O_RDONLY);

	char *line;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	printf("%d", fd);
	close(fd);
	
}*/
