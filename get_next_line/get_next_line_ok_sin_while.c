/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:49:25 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/14 14:04:43 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char    *ft_free(char *buffer, char *buf)
{
        char    *temp;

        temp = ft_strjoin(buffer, buf);
        free(buffer);
        return (temp);
}

char *ft_read_fd(int fd, char *res)
{
	int byte_read;
	char *buffer;
	
	byte_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!res)
	{
		res = (char *)malloc(sizeof(char) * 1);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL || res == NULL)
		return (NULL);
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_strjoin(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (res);
}

char *ft_read_line(char *buffer)
{
	char *line;
	int i;
	i = 0;
	//write(1, "antes", 5);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
	{
		free(buffer);
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
	//free(buffer);
	return (line);
}



char *ft_next_line(char *buffer)
{
	int i;
	char *next_line;
	int j;

	i = 0;
	/*if (buffer == NULL)
		return (NULL);*/
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i++])
	{
		free(buffer);
		return (NULL);
	}
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (next_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	//write(1, "en", 2);
	while (buffer[i])
		next_line[j++] = buffer[i++];
	/*if (buffer[i] && buffer[i] != '\n')
		next_line[j] = '\n';*/
	free(buffer);
	return (next_line);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_fd(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_read_line(buffer);
	//printf("Line:\n%s\n", line);
	/*if (line == NULL)
	{
		free(buffer);
		return (NULL);
	}*/
	buffer = ft_next_line(buffer);
	/*if (buffer == NULL)
		return (NULL);*/
	return (line);
}

int main()
{
	int fd;
	char *buffer;
	int i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	//buffer = get_next_line(file);
	//write(1, "aaa", 3);
	//printf("%d", file);
	while ((buffer = get_next_line(fd)))
	{
		//write(1, "ee", 2);
		printf("%d: %s\n",i++, buffer);
	}
	//printf("%s",ft_next_line(buffer));
}
