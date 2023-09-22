
#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	int len;

	len = ft_strlen(s);
	write(fd, s++, len);
}

/*int main()
{
	char str[] = "hola";
	ft_putstr_fd(str, 2);
}*/
