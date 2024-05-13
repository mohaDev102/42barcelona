/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:01:02 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/13 13:12:06 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void close_pipe(int in, int out)
{
    if (in != -1)
        close(in);
    if (out != -1)
        close(out);
}

void wait_children(t_pipe *info, int *exit)
{
    int i;
    int status;
    (void)exit;
    i = 0;
    while (i < info->n_commands)
    {
        waitpid(info->pid[i], &status, 0);
        i++;
    }
    dup2(info->std_in, STDIN_FILENO);
    dup2(info->std_out, STDOUT_FILENO);
    free(info->pid);
    // if (WIFEXITED(status))
    //     *exit = (WIFEXITED(status));
    // señales
    // else if ()
    // {

    // }    
}
// busca el path en el env

void search_path(t_cmd **cmd, char *env[])
{
    char *path;
    char **paths;
    char *path_cmd;
    char *path_final;

    path_cmd = NULL;
    (void)env;
    (void)cmd;
    int i = 0;
    path = getenv("PATH");
    if (!path)
        exit(1);
    paths = ft_split(path, ':');
    if (access(*(*cmd)->args, X_OK) != -1)
        execve((*cmd)->args[0], (*cmd)->args, env);
    while (paths[i] != NULL)
    {
        path_final = ft_strjoin(paths[i], "/");
        path_cmd = ft_strjoin(path_final, *(*cmd)->args);
        execve(path_cmd, (*cmd)->args, env);
        free(path_final);
        free(path_cmd);
        i++;
    }
    // solo pilla permission denied el command not found no lo pilla !!!
    // if (access((*cmd)->args[0], F_OK) == -1)
    // {
    //     write(2, "Permission denied\n", 18);
    //     exit(126);
    // }
    // else
    // {
    //     if ((*cmd)->args != NULL)
    //         write(2, "Command not found\n", 19);
    //     exit(127);
    // }
}
// ejecutar los comando tanto si es /bin/ls como si es ls
void exec_cmd(char *path, t_cmd **cmd, char *env[])
{
    (void)path;
    (void)cmd;
    (void)env;
}

int	parser_lstsize(t_cmd *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int executor(t_cmd **cmd, t_lexer **lexer, char **env)
{
    t_pipe data;
    int i = 0;
    (void) lexer;
    data.n_commands = parser_lstsize(*cmd);
    // data.n_commands = 1;
    data.fd[0] = -1;
    data.fd[1] = -1;
    data.pid = malloc(sizeof(pid_t) * data.n_commands);
    if (!data.pid)
        return (-1);
    data.std_in = dup(STDIN_FILENO);
    data.std_out = dup(STDOUT_FILENO);
    while ((*cmd) != NULL)
    {
        if (pipe(data.fd) == -1)
            return (-1);
        data.pid[i] = fork();
        if (data.pid[i] == -1)
            return (-1);
        if (data.pid[i] == 0)
        {
            if ((*cmd)->next)
                dup2(data.fd[1], STDOUT_FILENO);
            redirections(cmd, data, env);
            close(data.fd[1]);
            close(data.fd[0]);
            search_path(cmd, env);
        }
        // mirar los permisos y luego poner command not found
            // execve("/bin/ls", (*cmd)->args, env);
            // exec_cmd(path, cmd, env);
        dup2(data.fd[0], STDIN_FILENO);
        close_pipe(data.fd[0], data.fd[1]);
        (*cmd) = (*cmd)->next;
        i++;
    }
    // tengo que hay el wait_children
    // printf("%d", i);
    wait_children(&data, 0);
    return (0);
}