#include <stdio.h>
#include <string.h>
void *ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	to_find;

	i = 0;
	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (i < n && str[i])
	{
		if (str[i] == to_find)
			return (&str[i]);
		i++;
	}
	return (NULL);

}
/*int	main()
{
	char s1[10] = "";
	//char *res = memchr(0x7ffd376c24f0, 471(d7), 44);
	//char *res1 = ft_memchr(s1, 'o', 2);
	//printf("%s\n", res);
	//printf("%s\n", res1);

}*/
