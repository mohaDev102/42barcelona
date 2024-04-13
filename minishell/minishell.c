
#include "minishell.h"

int main(void)
{
    char *line;

    while (1)
    {
        line = readline("minishell$ ");
        if (line)
            add_history(line);
        if (!ft_strncmp(line, "exit", 4))
        {
            write(1, "exit\n", 5);
            free(line);
            exit(0);
        }
        // ft_lexer(line);
    }
    free(line);
    return (0);
}