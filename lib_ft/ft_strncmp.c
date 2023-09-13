
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (i < n)
			if (s1[i] != s2[i])
				return ((unsigned char) s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*int main()
{
	char s1[100] = "test\200";
	char s2[100] = "test\0";
	printf("original:%d\n", strncmp(s1, s2, 7));
	printf("%d\n", ft_strncmp(s1, s2, 7));
}*/
