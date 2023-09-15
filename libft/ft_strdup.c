
#include "libft.h"
#include <string.h>
char *ft_strdup(const char *s1)
{

  char *ptr;
  size_t len;
  size_t i;
 
  if (s1 == NULL)
	 return (NULL); 
  ptr = (char*)s1;
  len = ft_strlen(ptr) + 1;
  ptr = (char *)malloc(len);
  i = 0;
  while (i < len)
  {
	ptr[i] = s1[i];
	i++;
  }
  ptr[i] = '\0';
  return (ptr);

}

/*int main()
{
	char c[100] = "sadfvbf";
	printf("%s\n", ft_strdup(c));
	printf("%s\n", strdup(c));
}*/
