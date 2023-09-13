
#include <stdio.h>
#include <ctype.h>
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*int	main()
{
	int c = 32;
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(c));
}*/

