/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:28:48 by alounici          #+#    #+#             */
/*   Updated: 2024/05/08 20:01:29 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minishell.h"

//flag 1 = -n

void	print_env(char *echocmd, int i, t_list *envlist)
{
	t_list	*tmp;
	char	*envname;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(echocmd) - i;
	envname = malloc(sizeof(char) * len + 1);
	while (echocmd[i])
		envname[j++] = echocmd[i++];
	tmp = NULL;
	init_list(tmp);
	tmp = envlist;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, envname) == 0 && tmp)
		{
			printf("%s", tmp->name);
			printf("%s", tmp->content);
			return ;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_echo(char *echocmd, int flag, t_list *envlist)
{
	int		i;

	i = 0;
	if (echocmd == NULL || echocmd[i] == '\0')
	{
		if (flag == 0)
			write(1, "\n", 1);
		return ;
	}
	else
	{
		while (echocmd[i + 1] && (echocmd[i] != 36))
			printf("%c", echocmd[i++]);
		if (echocmd[i] == 36 && echocmd[i + 1] > 32 && echocmd[i + 1] < 127)
			print_env(echocmd, i + 1, envlist);
		else
		{
			while (echocmd[i])
				printf("%c", echocmd[i++]);
		}
	}
	if (flag == 0)
		printf("\n");
}
