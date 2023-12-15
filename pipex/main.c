#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *env[]) {
    /*if (argc < 5) {
        printf("Uso: %s <output_file1> <command1> <output_file2> <command2>\n", argv[0]);
      
    }*/

	int fd;
	fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	
	char *args[2];
	
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	// hacer un split para tener separado el comando con parametros
	// hay que cambiar el "/bin/ls" por la ruta correcta en funcion del comando que se pongo
	execve("/bin/ls", args, NULL);
	//write(1, &env, 2);
	//printf("env: %s", env);
	
	return (0);
}

