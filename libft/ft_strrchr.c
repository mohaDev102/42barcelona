#include <string.h>
#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	const char *i;

	i = 0;
	i = s;

	while (*i != '\0')
		i++;
	while (i >= s)
	{
		if (*i == c)
			return (char *)i;	
		i--;
	}
	return NULL;
}
/*int	main()
{
	char c[100] = "hola que tal";
	
	printf("%s\n", strrchr(c, 'a'));
	printf("%s\n", ft_strrchr(c, 'a'));
}*/
