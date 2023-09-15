#include <stdio.h>
#include <string.h>
#include "libft.h"
void *ft_memset(void *ptr, int value, size_t num) {
    unsigned char *byte_ptr;
    unsigned char byte_value;

    byte_ptr = (unsigned char *)ptr;
    byte_value = (unsigned char)value;
    while (num > 0) {
        *byte_ptr = byte_value;
        byte_ptr++;
        num--;
    }
    return (ptr);
}

/*t	main()
{
	char str[256] = "hola buenos dias como se encuentra usted";
	char str2[256] = "hola buenos dias como se encuentra usted";
	memset(str + 2, 'A', 8*sizeof(char));
	ft_memset(str2 + 2, 'A', 8*sizeof(char));
	//ft_memset(str, 'A', sizeof(str));
	printf("Original: %s\n", str);
	printf("Personal: %s\n", str2);
}*/
