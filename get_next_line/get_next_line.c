/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:49:25 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/22 12:46:12 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	buffer = 0;
	return (temp);
}

char *ft_read_file(int fd, char *res)
{
	int byte_read;
	char *buffer = NULL;
	
	byte_read = 1;
	if (!res)
	{
		res = (char *)malloc(sizeof(char) * 1);
		if(res == NULL)
		{
			return (NULL);
		}
		res[0] = '\0';
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(res);
		return (NULL);
	}
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		//res = ft_strjoin(res, buffer);
		res = ft_free(res, buffer);
		// if (res == NULL)
		// {
		// 	free(buffer);
		// 	return (NULL);
		// }
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	buffer = 0;
	return (res);
}

char *ft_read_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!buffer || !buffer[i])
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (line == NULL)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char *ft_next_line(char *buffer)
{
	int i;
	char *next_line;
	int j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++])
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (next_line == NULL)
	{
		//free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	buffer = 0;
	return (next_line);
}

char *get_next_line(int fd)
{
	static char *buffer = NULL;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
		line = ft_read_line(buffer);
	if(!line)
	{
		//free(line);
		return (NULL);
	}
	buffer = ft_next_line(buffer);
	return (line);
}

/*int main()
{
	int fd;
	char *buffer;
	int i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	while ((buffer = get_next_line(fd)))
	{
		printf("%d: %s",i++, buffer);
		free(buffer);
	}
	close(fd);
}*/
