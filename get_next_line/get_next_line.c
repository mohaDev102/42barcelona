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

char *ft_read_file(char *file)
{
	int nfile;
	char *buffer;

	nfile = open(file, O_RDONLY);
	if (nfile == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer = (char *)malloc(20);
	if (buffer == NULL)
	{
		close(nfile);
		return NULL;
	}
	read(nfile, buffer, 20);
	close(nfile);
	return (buffer);
}

char *get_next_line(int fd, char **line)
{
	char str;
	str = (char)fd;
	return ("");
}

int main()
{
	printf("%s",ft_read_file("test.txt"));
}
