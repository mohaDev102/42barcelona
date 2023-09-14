
#include "libft.h"
char *ft_strdup(const char *s1)
{

  char *ptr;
  size_t len;
  size_t i;
  
  //len = ft_strlen(ptr) + 1;
  ptr = (char*)s1;
  len = ft_strlen(ptr) + 1;
  ptr = (char *)malloc(len);
  
  if (ptr == NULL)
      return (NULL);
  
  while (i < len)
  {
	ptr[i] = s1[i];
	i++;
  }
  ptr[i] = '\0';
  return (ptr);

}
