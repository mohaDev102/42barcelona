/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:58:34 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/29 02:40:40 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <termios.h>
#include <signal.h>
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s++, len);
}

void handle_sigint_heredoc(int sig)
{
    struct termios  term_attr;

	if (sig == SIGINT)
	{
		if (isatty(STDIN_FILENO))
		{
			if (tcgetattr(STDIN_FILENO, &term_attr) != -1)
			{
				term_attr.c_lflag |= ECHO;
				tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);
			}
		}
		exit(130);
	}
}

void    create_herdoc(char *limiter, char *path)
{
    int     fd;
    char    *str;
	char	*temp;

    signal(SIGINT, handle_sigint_heredoc);
    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0)
        return ;
    str = readline(" ");
    while (str && ft_strcmp(limiter, str) != 0)
    {
        temp = ft_strjoin(str, "\n");
        ft_putstr_fd(temp, fd);
        free(temp);
		free(str);
        str = readline(" ");
    }
    close(fd);
    free(str);
    exit(0);
}

void    do_herdoc(t_redir *tmp, int i)
{
    char    *num;
    char    *path;
    pid_t   pid;
	int status;

	status = 0;
    num = ft_itoa(i);
    path = ft_strjoin("minishell", num);
    pid = fork();
    free(num);
	if (pid == 0)
		create_herdoc(tmp->file, path);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			status = 131;
		else if (WTERMSIG(status) == SIGINT)
			status = 130;
	}
	free(tmp->file);
	tmp->file = ft_strdup(path);
	exit_status(status);
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
