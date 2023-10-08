/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:39:04 by mel-atta          #+#    #+#             */
/*   Updated: 2023/10/07 19:41:29 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>

int		ft_putnbr(int nb);
int		ft_putnbrabs(unsigned int nb);
int		ft_putchar(char c, int flag);
int		ft_putstr(char *str, int flag);
size_t	ft_strlen(const char *c);
int		ft_puthexa(int decimal, int is_upper, int flag);
int		ft_putptr(const long *ptr, int flag);
int		ft_printf(char const *str, ...);
#endif
