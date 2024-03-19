/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:49:25 by mel-atta          #+#    #+#             */
/*   Updated: 2023/11/04 00:20:21 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	if (buffer)
		free(buffer);
	buffer = NULL;
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (NULL);
}

char	*ft_read_file(int fd, char *res)
{
	int		byte_read;
	char	*buffer;

	byte_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (ft_free(res, 0));
	while (byte_read > 0 && (ft_strchr(res, '\n') != 0))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free(res, buffer));
		if (byte_read > 0)
		{
			buffer[byte_read] = 0;
			res = ft_strjoin(res, buffer);
			if (!res)
				return (ft_free(res, buffer));
		}
	}
	free(buffer);
	return (res);
}

char	*ft_read_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
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

char	*next_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t j;
	size_t cant;

	i = 0;
	j = 0;
	//if (!buffer || buffer[i] == '\0')
	//	return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	cant = ft_strlen(buffer + i);
	if (cant == 0)
		return (ft_free(buffer, 0));
	line =  (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (line == NULL)
		return (ft_free(buffer, 0));
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}

char	*beefreader(int fd, char *buffer)
{
	char	*tmp;
	int		beefs_read;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free(buffer, 0));
	beefs_read = 1;
	while (beefs_read > 0 && (ft_strchr(buffer, '\n') != 0))
	{
		beefs_read = read(fd, tmp, BUFFER_SIZE);
		if (beefs_read == -1)
			return (ft_free(buffer, tmp));
		//if (beefs_read == 0 && !buffer)
		//	return (free(tmp), NULL);
		if (beefs_read > 0)
		{
			
			tmp[beefs_read] = 0;
			buffer = ft_strjoin(buffer, tmp);
			if (!buffer)
				return (ft_free(buffer, tmp));
		}
		//if (!buffer)
		//	return (free(tmp), NULL);
	}
	free(tmp);
	return (buffer);
}


char	*ft_next_line(char *buffer)
{
	int		i;
	char	*next_line;
	int		j;
	int		cant;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	cant = ft_strlen(buffer + i);
	if (cant == 0)
		return (ft_free(buffer, 0));
	next_line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i) + 1);
	if (next_line == NULL)
		return (ft_free(buffer, 0));
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char *line_up(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
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

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	// buffer = beefreader(fd, buffer);
	if (buffer == NULL)
		return (ft_free(buffer, 0));
	// line = ft_read_line(buffer);
	line = line_up(buffer);
	if (!line)
	{
		buffer = ft_free(buffer, 0);
		return (NULL);
	}
	// buffer = next_line(buffer);	
	buffer = ft_next_line(buffer);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *buffer;
// 	int i;

// 	i = 1;
// 	fd = open("oneline.txt", O_RDONLY);
// 	while ((buffer = get_next_line(fd)))
// 	{
// 		printf("%d: %s",i++, buffer);
// 		free(buffer);
// 	}
// 	close(fd);
// }
