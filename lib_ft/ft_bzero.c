
#include <stdio.h>	
#include <string.h>	

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char *byte_ptr;

	byte_ptr = (unsigned char *)ptr;

	while (n > 0)
	{
		*byte_ptr = 0;
		byte_ptr++;		
		n--;
	}

}

/*int	main()
{
	int number;
	char str[20] = "hola";
	char str2[10] = "hola";
	printf("%s\n",str);
	printf("%s\n", str2);
	bzero(str, 4);
	printf("original:%s\n", str);
	ft_bzero(str2, 4);
	printf("custom:%s\n",str2);

}*/
