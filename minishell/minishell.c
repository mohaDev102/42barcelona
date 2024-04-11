
#include "minishell.h"

int main(void)
{
    char *line;

    while (1)
    {
        line = readline("minishell >");
        if (line)
            add_history(line);
        if (!ft_strncmp(line, "exit", 4))
        {
            free(line);
            exit(1);
        }
        printf("%s\n", line);
    }
    free(line);
    return (0);
}