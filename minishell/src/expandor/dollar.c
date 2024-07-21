/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:46:23 by alounici          #+#    #+#             */
/*   Updated: 2024/07/21 11:47:51 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*dollar(char *str, int i, t_list **envlist)
{
	char	*res;

	if (str[i + 1] && str[i + 1] == '?')
		res = last_exit();
	else
		res = handle_dollar(str, envlist);
	return (res);
}

int	dollar_found(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

char	*handle_dollar3(char *res, char *auxbis)
{
	char	*temp;

	temp = NULL;
	if (res != NULL && auxbis)
	{
		temp = ft_strjoinexp(res, auxbis);
		free(res);
		res = temp;
		free(auxbis);
	}
	else if (auxbis)
	{
		temp = ft_strdup(auxbis);
		res = temp;
		free(auxbis);
	}
	return (res);
}

char	*handle_dollar2(char *splited, t_list **envlist, char *auxbis)
{
	char	*aux;

	aux = NULL;
	if (strchrint(splited, '$') != -1)
	{
		aux = extract_var_name(splited, 0);
		auxbis = my_getenv(*envlist, aux, 3);
		free(aux);
	}
	else
		auxbis = ft_strdup(splited);
	return (auxbis);
}

char	*handle_dollar(char *str, t_list **envlist)
{
	char	**splited;
	char	*res;
	char	*auxbis;
	int		i;

	i = 0;
	res = NULL;
	auxbis = NULL;
	if (strchrint(str, '$') == ((int)ft_strlen(str) - 1))
		return (ft_strdup(str));
	splited = ft_splitexp(str, '$');
	while (splited[i])
	{
		auxbis = handle_dollar2(splited[i], envlist, auxbis);
		res = handle_dollar3(res, auxbis);
		free(splited[i]);
		i++;
	}
	free(splited);
	return (res);
}
