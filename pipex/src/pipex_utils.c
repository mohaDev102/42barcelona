
#include "pipex.h"

char *ft_getenv(char *name, char *env[])
{
	int i;
	char **var;

	i = 0;
	while (env[i] != NULL)
	{
		var = ft_split(env[i], '=');
		if (var != NULL && var[0] != NULL && var[1] != NULL)
		{
			if (ft_strcmp(var[0], name) == 0)
				return (var[1]);
		}
		free(var);		
		i++;
	}
	return (NULL);
}

char **find_path(char *env[])
{
	char **paths;
	char *path_sis;
	char **paths_pars = NULL;
	int i;
	int count;

	i = 0;
	count = 0;
	path_sis = ft_getenv("PATH", env);
	paths = ft_split(path_sis, ':');
	while (paths[count] != NULL)
		count++;
	paths_pars = (char **)malloc((count + 1) * sizeof(char *));
	while (paths[i] != NULL)
	{
		paths_pars[i] = paths[i];
		i++;
	}
	paths_pars[i] = NULL;
	return (paths_pars);
}

void ft_error(char *cmd)
{
	write(2, "Error:\n", 7);
	write(2, "Command not found :", 19);
	write(2, &cmd[0], ft_strlen(&cmd[0]));
	exit(127);
}

void ft_iterar_paths(char **paths, char **cmd, char *env[])
{
	int i;
	char	*path_cmd;
	char	*path; 

	i = 0;
	path_cmd = NULL;
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		path_cmd = ft_strjoin(path, cmd[0]);
		execve(path_cmd, cmd, env);
		free(path);
		free(path_cmd);
		i++;
	}
}

char *ft_check_cmd(char *env[], char *argv[])
{
	char **cmd;
	char **paths;

	paths = find_path(env);
	cmd = ft_split(*argv, ' ');
	if (access(cmd[0], X_OK) != -1)
		execve(cmd[0], cmd, env);
	else if (access(cmd[0], X_OK) == -1)
		ft_iterar_paths(paths, cmd, env);
	if (access(cmd[0], F_OK) != -1)
    {
		write(2, "Permission denied\n", 18);
		exit(126);
    }
    else 
    {
		if (cmd[0] != NULL)
			ft_error(*cmd);
    }
	free(cmd);
	return (NULL);
}

void ft_exec_cmd(char *argv[], char *env[])
{
	char **paths;

	paths = find_path(env);
	ft_check_cmd(env, argv);
}