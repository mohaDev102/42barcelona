#include <stdio.h>
#include <unistd.h>
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

    // Calcula la longitud de la cadena de origen (src).
    while (src[src_len] != '\0') {
        src_len++;
    }

    // Copia src a dest hasta un máximo de n - 1 caracteres.
    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    // Asegura que dest tenga un carácter nulo al final.
    dest[i] = '\0';

    return src_len;
}

/*int	main()
{
	char src[10] = "lorem";
	char dest[10] = "";	
	printf("%d\n", ft_strlcpy(dest, src, 15));
	write(1, dest, 15);
}*/
