#include <stdio.h>
#include <unistd.h>
#include "../inc/minishell.h"


// void ft_putnbr(int num)
// {
//     char res;
//     if (num > 9)
//         ft_putnbr(num / 10);
//     res = num % 10 + '0';
//     write(1, &res, 1);
// }

int     ft_strstr(char **env, char *find_to)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    j = 0;
	if (!find_to)
		return (0);
	while (env[i])
	{
        j = 0;
        while (env[i][j])
        {
		    if (env[i][j] == find_to[k])
            {
                while (find_to[k] != '\0' && env[i][j] == find_to[k])
                {
                    j++;
                    k++;
                }
                if (find_to[k] == '\0')
                    return (i);
            }
            k = 0;
            j++;
        }
                    //  ft_putnbr(i);
        i++;
    }
	return (0);
}

// int main(void)
// {
//     char *mat[] = {"dsfkjfhjskhfjksh", "ho"};
//     printf("%d\n", ft_strstr(mat, "hola"));
// }