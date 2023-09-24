#include "libft.h"
#include <stdio.h>
#include <string.h>
char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	size_t	i;
	int	aux;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*to_find == *str && i < n )
		{
			i = 0;
			aux = 0;
			//printf("%s\n", str);
			while (to_find[i] != '\0')
			{
				if (str[i] != to_find[i])
				{
					aux = 1;
				}
				i++;
			}
			if (aux == 0)
				//printf("dentro del if valor str: %s\n", str);
				return (str);
		}
		str++;
	}
	return (0);
}

int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	char find[] = "lorem";
	size_t n = 0;
	//printf("custom:%s\n", ft_strnstr(str, find, n));
	printf("original:%s\n", strnstr(str, find, n));
}
