/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:59:49 by alounici          #+#    #+#             */
/*   Updated: 2024/07/20 19:49:18 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int strchrint(char *str, char c)
{
    unsigned int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

char *extract_var_name(char *str, int i)
{
	int j;
	int k;
    char *var;

    j = i;
    k = 0;
    if (str[i] == '$')
        j++;
    while (str[i] && (ft_isalpha(str[i + 1]) || ft_isdigit(str[i + 1])) \
    && str[i + 1] != '$' && str[i + 1] != '\"' && str[i + 1] != '\'')
        i++;
    var = malloc(sizeof(char) * (i - j + 2));
    if (var == NULL)
        return(NULL);
    while (j <= i)
            var[k++] = str[j++];
    var[k] = '\0';
    return (var);
}

char	*ft_strjoinexp(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}

char *last_exit()
{
    char *res;
    res = ft_itoa(exit_status(0));
    return (res);
}

// int	exit_status(int value)
// {
// 	static int	prev = 0;
// 	int			ret;

// 	ret = prev;
// 	prev = value;
// 	return (ret);
// }

// void	set_value(int *i, int *k)
// {
// 	*i = 0;
// 	*k = 0;
// }

// void 	handle_quote(char **str, int j)
// {
// 	int i;
// 	int k;

// 	set_value(&i, &k);
// 	if (closed_quote(str[j]) == 0)
//     {
// 		free(str[j]);
//     	str[j] = ft_strdup("");
//     }
// 	else
// 	{
// 		while (str[j][i])
// 		{
// 			if (str[j][i] == '\'' || str[j][i] == '\"')
// 			{
// 				k = quote_erase(str, j, i);
// 				if (k == 0 || (unsigned int)k >= ft_strlen(str[j]))
// 					return ;
// 				i = k - 1;
// 			}
// 			else
// 				i++;
// 		}

// 	}
// }