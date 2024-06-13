/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:58:34 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/13 16:54:09 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <termios.h>
#include <setjmp.h>

static struct {
    sigjmp_buf jmpbuf;
    struct termios saved_term_attr;
} global_context;
// static sigjmp_buf jmpbuf;

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s++, len);
}

void handle_sigint_heredoc(int sig) {
    (void)sig;
    if (isatty(STDIN_FILENO))
	{
        tcsetattr(STDIN_FILENO, TCSANOW, &global_context.saved_term_attr);
    }
    write(STDOUT_FILENO, "\n", 1);
    siglongjmp(global_context.jmpbuf, 1);
}

void	create_herdoc(char *limiter, char *path)
{
	int		fd;
	char	*str = NULL;
	// pid_t	pid;
	// int status;


	if (isatty(STDIN_FILENO)) 
	{
        tcgetattr(STDIN_FILENO, &global_context.saved_term_attr);
    }
    signal(SIGINT, handle_sigint_heredoc);
    if (sigsetjmp(global_context.jmpbuf, 1) != 0) 
	{
        if (fd >= 0)
			close(fd);
        // if (str)
		// 	free(str);
        return;
    }
	fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		return ;
	//  receive_signal(1, 0); //, fd);
	str = readline(" ");
	while (str && ft_strcmp(limiter, str) != 0)
	{
		str = ft_strjoin(str, "\n");
		ft_putstr_fd(str, fd);
		free(str);
		str = readline(" ");
	// 	waitpid(pid, &status, 0);
	// 		if (WIFEXITED(status))
	// 			status = WEXITSTATUS(status);
	// 		printf("1 = %d", status);
	// 	if (WIFSIGNALED(status))
	// 	{
	// 		if (WTERMSIG(status) == SIGQUIT)
	// 			status = 131;
	// 		else if (WTERMSIG(status) == SIGINT)
	// 		{	status = 130;
	// 		close(fd);
	// 		}
	// 		printf("2 = %d", status);

	// 	}
	// 	if (status == 130)
	// 	{
	// 		write(1, "dans hd", 7);
	// 	}
	}
	// exit_status(status);
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
	// 	return;
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
