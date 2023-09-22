
#include "libft.h"
#include <unistd.h>

void ft_putendl_fd(char *s, int fd)
{
	int len;

	len = ft_strlen(s);
	write(fd, s++, len);
	write(fd, "\n", 1);
}
