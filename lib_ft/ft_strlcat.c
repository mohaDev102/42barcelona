#include <stddef.h>

size_t     ft_strlcat(char *dst, const char *src, size_t size)
{
	
	long i;
	
	i = 0;

	while (src[i] != '\0' && (size_t )i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	//while ((size_t)i < size)
	//{
		dst[i] = '\0';
	//	i++;
	//}
	return (i);
}
