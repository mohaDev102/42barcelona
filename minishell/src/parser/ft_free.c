/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:39:10 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/22 22:43:30 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	lexer_clear(t_cmd **cmd, t_lexer **lxr)
{
	t_lexer	*tmp;

	while (*lxr != NULL)
	{
		tmp = *lxr;
		*lxr = (*lxr)->next;
		free(tmp->value);
		free(tmp);
	}
	parser_free(cmd);
}

int	ft_len_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	ft_redir_clear(t_redir **redir)
{
	t_redir	*tmp;
	t_redir	*tmp2;

	tmp = *redir;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->file);
		free(tmp);
		tmp = tmp2;
	}
	*redir = NULL;
}

void	parser_free(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*temp1;

	temp = *cmd;
	while (temp)
	{
		temp1 = temp->next;
		ft_free(temp->args, ft_len_array(temp->args));
		ft_redir_clear(&temp->redir);
		free(temp);
		temp = temp1;
	}
	*cmd = NULL;
}

char	**ft_free(char **mat, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(mat[j]);
		j++;
	}
	free(mat);
	return (NULL);
}
