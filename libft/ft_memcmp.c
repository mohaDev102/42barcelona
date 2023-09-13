#include <stdio.h>
#include <string.h>
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	const unsigned char *ptr1 = s1;
    	const unsigned char *ptr2 = s2;

	i = 0;
	while (i < n)
	{
		if (i < n)
		{
			if (ptr1[i] > ptr2[i])
				return (1);
			else if (ptr1[i] < ptr2[i])
				return (-1);
		}
		i++;
	}		
	return (0);

}
/*int	main()
{
	char s1[] = "abcdefgh";
	char s2[] = "abcdwxyz";
	printf("%d\n", memcmp(s1, s2, 6));
	printf("%d\n", ft_memcmp(s1, s2, 6));
}*/
