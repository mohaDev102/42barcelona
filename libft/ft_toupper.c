#include <stdio.h>
#include <ctype.h>
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*int	main()
{
	int c = 65;
	
	printf("%d\n", toupper(c));
	printf("%d\n", ft_toupper(c));
}*/
