
#include <stddef.h>
void *ft_calloc(size_t nmemb, size_t size)
{
	size_t *size_mem = nmemb * size;

	size_t *ncalloc = (int *)malloc(size_mem * sizeof(int *));
	return ncalloc;
}
