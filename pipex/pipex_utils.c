
#include "pipex.h"

// comprobar si el path ejecuta y en caso que no, concatenar el path con el argv y si tampoco pues comando not found
char *ft_check_cmd(char *paths, char *env[], char *argv[])
{
	char *path;
	char *path_cmd;
	char **cmd;

	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) != -1)
	{
		// ejecutamos el comando y lo pasamos al archivo
		execve(cmd[0], cmd, env);
	}
	else
	{
		// ajuntamos cada path con el comando que hayan pasado y 
		// luego mirar si se puede ejecutar si funcion bien
		// sino error command not found
			path = ft_strjoin(paths, "/");
			path_cmd = ft_strjoin(path, cmd[0]);
			if (access(path_cmd, X_OK) != -1)
			{
				execve(path_cmd, cmd, env);
			}
		//else
			//error_cmd("command not found");
		free(path);
		free(path_cmd);
	}
	return (NULL);
}
