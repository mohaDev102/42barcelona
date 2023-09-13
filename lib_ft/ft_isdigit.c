#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/*int	main()
{
	int n = '0';
	while (n <= '9')
	{
		printf("%d", ft_isdigit(n));
		n++;
	}
}*/
