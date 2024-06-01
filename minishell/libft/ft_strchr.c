#include "../inc/minishell.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	//int	i;

	//i = 0;
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}