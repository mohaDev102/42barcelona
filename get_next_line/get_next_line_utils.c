
#include <stdlib.h>
#include <stddef.h>

size_t  ft_strlen(const char *c)
{
        size_t  i;

        i = 0;
        while (c[i] != '\0')
        {
                i++;
        }
        return (i);
}

void    *ft_memchr(const void *s, int c, size_t n)
{
        size_t                  i;
        unsigned char   *str;
        unsigned char   to_find;

        i = 0;
        str = (unsigned char *)s;
        to_find = (unsigned char)c;
        while (i < n)
        {
                if ((unsigned char)str[i] == (unsigned char)to_find)
                        return (&str[i]);
                i++;
        }
        return (NULL);
}

char    *ft_strchr(const char *str, int c)
{
        return (ft_memchr(str, c, ft_strlen(str) + 1));
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *res;
        int             i;
        int             j;

        i = 0;
        j = 0;
        if (s1 == NULL || s2 == NULL)
                return (NULL);
        res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
        if (res == NULL)
                return (NULL);
        while (s1[i] != '\0')
        {
                res[i] = s1[i];
                i++;
        }
        while (s2[j] != '\0')
        {
                res[i++] = s2[j++];
        }
        res[i] = '\0';
        return (res);
}
