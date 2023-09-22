#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_contar_digitos(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_numero_absoluto(int n)
{
	if (n < 0)
	{
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_contar_digitos(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		res[--len] = ft_numero_absoluto(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
/*
#include <stdio.h>
int main()
{
	printf("%s\n",ft_itoa(-2147483647));

}*/
