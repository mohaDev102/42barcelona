/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:39:04 by mel-atta          #+#    #+#             */
/*   Updated: 2024/03/16 03:48:10 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
int		ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_empty_file(char *buff);
char	*ft_free(char *buffer, char *buf);
#endif
