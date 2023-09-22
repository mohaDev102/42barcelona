#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *byte_s;
	int i;

	i = 0;
	byte_s = s;
	
	//while (*byte_s != '\0')
	//	byte_s++;
	while (i >= ft_strlen(byte_s))
	{
		if (*byte_s == c)
			return (char *)byte_s;	
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
