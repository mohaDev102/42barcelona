#include <stdio.h>
#include <unistd.h>
int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, size_t n)
{
	unsigned int i;
	unsigned int srclen;
	unsigned int destlen;
	
	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	while (dest[i] != '\0')
		i++;
	
	if (src[i] == '\0')
		return (srclen);
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (destlen);
}
/*int	main()
{
	char src[10] = "lorem";
	char dest[10] = "";	
	printf("%d\n", ft_strlcpy(dest, src, 15));
	write(1, dest, 15);
}*/
