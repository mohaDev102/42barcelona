
#ifndef MINISHELL
# define MINISHELL
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum s_type
{
	NOTH = 0,
	PIPE,
	LESS,
	LESS_L,
}	t_type;

typedef struct s_lexer
{
	char			*value;
	struct t_type	*type;
	struct s_lexer	*next;
}					t_lexer;

int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *s1, char *s2);
#endif