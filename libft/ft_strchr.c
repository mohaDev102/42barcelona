
#include <stdio.h>
#include <string.h>

char *ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (((char *)str + i));
	return (NULL);
}

/*int main()
{
	char c[100] = "0x55ea5613e020";
	printf("%s\n", strchr(c, "teste"));
	printf("%s\n", ft_strchr(c, "teste"));
}*/
