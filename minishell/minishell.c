
#include "minishell.h"
int	g_error = 0;

int	main(int argc, char *argv[])
{
	t_lexer *lexer;

	lexer = NULL;
	(void)argv;
	if (argc > 1)
	{
		printf("Error\n");
	}
	receive_signal(1);
    while (1)
    {
        receive_signal(0);
        //write(1, "ici", 3);
        line = readline("minishell$ ");
           // receive_signals_block();
        //execve
        if (line)
            add_history(line);
        if (!ft_strncmp(line, "exit", 4))
        {
            write(1, "exit\n", 5);
            free(line);
            exit(0);
        }
        // ft_lexer(line);
        //receive_signal();
    }
    free(line);
//    return (g_return_value2);
}