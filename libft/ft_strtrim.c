
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
char *ft_strtrim(char const *s1, char const *set)
{
	
	//char *ptr_s1;
	//char *quitar;
	char *res;
	int len;
	int end;
	int i;
	//int j;
	i = 0;
	//j = 0;
	if (s1 == NULL)
		return (NULL);

	len = ft_strlen(s1);
	//res = malloc((len + 1) * sizeof(char));
	//if (res == NULL)
	//	return (NULL);
	while (i < len && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	
	end = len;
	while (end > i && ft_strchr(set, s1[end - 1]) != NULL)
	{
		end--;
	}
	int len_res = end - i;
	res = malloc(len_res + 1);
	if (res == NULL)
	{
		//printf("error de memoria!!!");
		return (NULL);
	}
	ft_strncpy(res, s1 + i, len_res);
	//res[len_res] = '\0';
	res[len_res] = 'a';
	//write(1, "", 23);
	return (res);
}
#include <stdio.h>
/*int main()
{
	char s1[100] = "abcabcholacaracolaabcabc";
	char set[100] = "abc";
	printf("%s\n", ft_strtrim(s1, set));
}*/

