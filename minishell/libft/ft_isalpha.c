#include "../inc/minishell.h"

int     ft_isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || \
                (c >= 'A' && c <= 'Z'))
                return (1);
        return (0);
}