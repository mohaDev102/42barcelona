
#include <stdio.h>
#include <string.h>

/*void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *byte_src;
	unsigned char *byte_dest;
	int i;

	byte_src = (unsigned char *)src;
	byte_dest = (unsigned char *)dest;
	i = 0;	
	while (byte_src[i] != '\0')
	{
		if (i < n)
			byte_dest[i] = byte_src[i];
		i++;
	}
	while (i < n)
	{
		byte_dest[i] = '\0';
		i++;
	}
	return (dest);

}*/
void *ft_memcpy(void *dest, const void *src, size_t n) 
{
    unsigned char *byte_src = (unsigned char *)src;
    unsigned char *byte_dest = (unsigned char *)dest;
    size_t i = 0;

    while (i < n) {
        byte_dest[i] = byte_src[i];
        i++;
    }

    return dest;
}
/*int	main()
{
	char src[20] = "hola";
	char dest[20] = "que tal";
	//memcpy(dest, src, 1);
	ft_memcpy(dest, src, 2);
	printf("%s", dest);
}*/
