#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"
#include <string.h>


char *ft_getenv(char *name, char *env[])
{
	int i;
	char **var;

	i = 0;
	while (env[i] != NULL)
	{
		//printf("%s", name);
		var = ft_split(env[i], '=');
		if (var != NULL && var[0] != NULL && var[1] != NULL)
		{
			if (ft_strcmp(var[0], name) == 0)
				return (var[1]);
		}
		free(var);
		//write(1, "ss", 2);
		i++;
	}
	//printf("%s", var[i]);
	return (NULL);
}

void	ft_child(char *argv[], char *process_fd, char **env)
{

	
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		//exit_free();
	dup2(fd, STDOUT_FILENO);
	dup2(process_fd[1], 1);
	close(process_fd[0]);
}


void	ft_parent(char *argv[], char *process_fd, char **env)
{
	
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		//exit_free();
	dup2(fd, );
	dup2(process_fd[0], STDIN_FILENO);
	close(process_fd[1]);
}

char **find_path(char *env[])
{

	// buscar la ruta del comando que pongan por paramentro
	char **paths;
	char *pat;

	//paths = NULL;
	pat = ft_getenv("PATH", env);
	paths = ft_split(pat, ':');
	//paths = (char *)malloc(sizeof(char *) * (ft_strlen(pat) + 1));
	/*while (paths[i] != NULL)
	{
		return (paths[i]);
		i++;
	}	*/
	return (paths);
}

// comprobar si el path ejecuta y en caso que no, concatenar el path con el argv y si tampoco pues comando not found
char *ft_check_cmd(char *paths, char *env[], char *argv[])
{
	char *path;
	char *path_cmd;
	char **cmd;
	//int i;

	//i = 0;
	cmd = ft_split(argv[2], ' ');
	if (access(cmd[0], X_OK) != -1)
	{
		// ejecutamos el comando y lo pasamos al archivo
		write(1, "if", 2);
		execve(cmd[0], cmd, env);
		//write(1, "if", 2);
	}
	else
	{
		// ajuntamos cada path con el comando que hayan pasado y 
		// luego mirar si se puede ejecutar si funcion bien
		// sino error command not found
		write(1, "else", 4);
			path = ft_strjoin(paths, "/");
			path_cmd = ft_strjoin(path, cmd[0]);
			if (access(path_cmd, X_OK) != -1)
			{
				write(1, "if2", 3);
				execve("/bin/cat", cmd, env);
				//write(1, "if2", 3);
			}
			//i++;
		//else
			//error_cmd("command not found");
		free(path);
		free(path_cmd);
	}
	return NULL;
}





int main(int argc, char *argv[], char *env[]) 
{
	pid_t pid;
	int fd[2];

    if (argc != 5) 
        printf("Uso: %s <output_file1> <command1> <output_file2> <command2>\n", argv[0]);
    if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
    pid = fork();
    if (pid == -1)
    {
	perror("fork");
	exit(EXIT_FAILURE);
    }
    if (pid == 0)
	ft_child(argv, fd, env);
    else
	ft_parent(argv, fd, env);
	return (0);
}

