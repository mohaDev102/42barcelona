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
	return NULL;
}


char *find_path(char *env[])
{

	// buscar la ruta del comando que pongan por paramentro
	char **paths;
	int i;
	char *pat;

	i = 0;
	//paths = NULL;
	pat = ft_getenv("PATH", env);
	//paths = (char *)malloc(sizeof(char *) * (ft_strlen(pat) + 1));
	while (env[i] != NULL)
	{
		paths = ft_split(pat, ':');
		i++;
	}	
	return (*paths);
}





int main(int argc, char *argv[], char *env[]) {
    /*if (argc < 5) {
        printf("Uso: %s <output_file1> <command1> <output_file2> <command2>\n", argv[0]);
      
    }*/
	(void) argc;
	int fd;
	fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	
	char *args[3];
	
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	// hacer un split para tener separado el comando con parametros
	printf("%s",find_path(env));
	//printf("ss");
	// hay que cambiar el "/bin/ls" por la ruta correcta en funcion del comando que se pongo
	//execve("/bin/ls", args, NULL);
	//write(1, &env, 2);
	//printf("env: %s", env);
	
	return (0);
}

