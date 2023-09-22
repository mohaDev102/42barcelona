#include "libft.h"
#include <stdio.h>
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int len;
	int i;
	char *res;
	
	len = ft_strlen(s);
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (s[i])
	{
		//printf("%s", "sss");
		res[i] = f(i, s[i]);
		//printf("%d\n", i);
		i++;
	}
	//res[len] = '\0';
	return (res);
}
/*char map_function(unsigned int index, char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}*/
/*int main()
{
	char str[] = "hola";	
	printf("%s\n", ft_strmapi(str, &map_function));

}*/
