/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 19:47:10 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 19:50:18 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void 	handle_quote(char **str, int j)
{
	int i;
	int k;

	set_value(&i, &k);
	if (closed_quote(str[j]) == 0)
    {
		free(str[j]);
    	str[j] = ft_strdup("");
    }
	else
	{
		while (str[j][i])
		{
			if (str[j][i] == '\'' || str[j][i] == '\"')
			{
				k = quote_erase(str, j, i);
				if (k == 0 || (unsigned int)k >= ft_strlen(str[j]))
					return ;
				i = k - 1;
			}
			else
				i++;
		}

	}
}

void	set_value(int *i, int *k)
{
	*i = 0;
	*k = 0;
}

int	exit_status(int value)
{
	static int	prev = 0;
	int			ret;

	ret = prev;
	prev = value;
	return (ret);
}