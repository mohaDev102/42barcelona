
#include "minishell.h"

// int g_return_value = 0;
//t_signal_num signal_num;

int main(void)
{
    char *line;
   // t_signal_num signal_num;

receive_signal(0);
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