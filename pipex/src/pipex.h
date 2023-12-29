

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>


char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void    *ft_memset(void *b, int c, size_t len);
int ft_strcmp(const char *s1, const char *s2);
char    *ft_check_cmd(char *env[], char *argv[]);
void    ft_exec_cmd(char *argv[], char *env[]);
#endif
