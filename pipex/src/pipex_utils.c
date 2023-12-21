
#include "pipex.h"

// comprobar si el path ejecuta y en caso que no, concatenar el path con el argv y si tampoco pues comando not found
char *ft_check_cmd(char *paths, char *env[], char *argv[])
{
	char *path;
	char *path_cmd;
	char **cmd;

	cmd = ft_split(*argv, ' ');
	path = ft_strjoin(paths, "/");
	path_cmd = ft_strjoin(path, cmd[0]);
	if (access(cmd[0], X_OK) != -1)
		execve(cmd[0], cmd, env);
	else if (access(path_cmd, F_OK | X_OK) != -1)
	{
		// ajuntamos cada path con el comando que hayan pasado y 
		// luego mirar si se puede ejecutar si funcion bien
		// sino error command not found
				execve(path_cmd, cmd, env);
			//if (access(path_cmd, X_OK) != -1)
			//{
			//}
			//error_cmd("command not found");
		//free(path);
		//free(path_cmd);
	}
	return (NULL);
}

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
	// buscar la ruta del comando que pongan por paramentro
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
	return (paths_pars);
}

void ft_exec_cmd(char *argv[], char *env[])
{
	char **paths;
	int i;

	paths = find_path(env);
	i = 0;
	while (paths[i] != NULL)
	{
		ft_check_cmd(paths[i], env, argv);
		i++;
	}
	if (access(paths[i], X_OK) == -1)
	{
		write(2, "Error: command not found\n", 25);
		exit(1);
	}
}