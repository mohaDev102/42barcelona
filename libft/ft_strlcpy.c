#include <stdio.h>
#include <unistd.h>
#include <bsd/string.h>
int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcpy(char *dest, const char *src, size_t n) {
    size_t src_len = 0;
    size_t i = 0;

    while (src[src_len] != '\0') {
        src_len++;
    }

    if (n == 0)
	    return (src_len);
    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return src_len;
}

/*int	main()
{
	char src[100] = "lorem ipsum dolor sit amet";
	char dest[100] = "";
	char dest1[100]	= "";
	printf("custom: %ld\n", ft_strlcpy(dest, src, 0));
	printf("original: %ld\n", strlcpy(dest1, src, 0));
	write(1, dest, 15);
	write(1, dest1, 15);

}*/
