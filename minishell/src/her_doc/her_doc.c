/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:58:34 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/21 11:58:35 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s++, len);
}

void	create_herdoc(char *limiter, char *path)
{
	int		fd;
	char	*str;

	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return ;
	str = readline(" ");
	while (str && ft_strcmp(limiter, str) != 0)
	{
		str = ft_strjoin(str, "\n");
		ft_putstr_fd(str, fd);
		free(str);
		str = readline(" ");
	}
	close(fd);
	free(str);
}

void	do_herdoc(t_redir *tmp, int i)
{
	char	*num;
	char	*path;

	num = ft_itoa(i);
	path = ft_strjoin("minishell", num);
	free(num);
	create_herdoc(tmp->file, path);
	free(tmp->file);
	tmp->file = ft_strdup(path);
	free(path);
}

void	her_doc(t_cmd *cmd)
{
	int		i;
	t_redir	*tmp;

	i = 0;
	while (cmd != NULL)
	{
		tmp = cmd->redir;
		while (tmp != NULL)
		{
			if (tmp->type == HERDOC)
			{
				do_herdoc(tmp, i);
				i++;
			}
			tmp = tmp->next;
		}
		cmd = cmd->next;
	}
}
