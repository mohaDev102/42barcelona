#include "../inc/minishell.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	to_find;

	i = 0;
	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)to_find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}