#include "../../inc/minishell.h"

void create_herdoc(char *limiter, char *path)
{
    // hacer el open y mirar si ya esta creado el file o no y despues de guardar en el file
    // printarlo y cerrar el archivo
    int fd;
    char *str;

    fd = open(path, O_CREAT |  O_WRONLY | O_TRUNC, 0655);
    if (fd < 0)
        return ;
    str = readline("minishell$ ");
    while (str && ft_strcmp(limiter, str) != 0)
    {
        str = ft_strjoin(str, '\n');
        printf("%s", str);
        free(str);
        str = readline("minishell$ ");
    }
    close(fd);
    free(str);
    // algo de señales
}


void do_herdoc(t_redir *tmp, int i)
{
    char *num;
    char *path;

    num = ft_itoa(i);
    path = ft_strjoin("minishell", num);
    free(num);
    create_herdoc(tmp->file, path);
    free(tmp->file);
    tmp->file = ft_strdup(path);
}


void her_doc(t_cmd *cmd, char **env)
{
    int i;
    t_redir *tmp;

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
                tmp = tmp->next;
            }
        }
        cmd = cmd->next;
    }
}