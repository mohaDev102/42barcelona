#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	while ((str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;		
		}
		else
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
		i++;
		return (res * sign);
	}
	return (res * sign);
}
/*int	main()
{
	char str[] = "\t\n\r\v\f 469 \n";
	printf("%d\n",ft_atoi(str));
	printf("%d\n",atoi(str));
}*/
