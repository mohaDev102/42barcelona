#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif
# include <limits.h>
# include <stdio.h>
# include "../readline/readline.h"
# include "../readline/history.h"
# include <stdlib.h>
# include <unistd.h>

int g_error;

# define PIPE_AS 124
# define LESS_AS 60
# define GREAT_AS 62

// int g_return_value2 = 0;

// typedef struct s_signal_num
// {
// 	int return_value;
// 	int sigindex;
// }	t_signal_num;

typedef enum s_type
{
	NOTH = 0,
	PIPE,
	LESS,
	LESS_L,
	GREAT,
	GREAT_L,
}					t_type;

typedef struct s_lexer
{
	char			*value;
	t_type			type;
	struct s_lexer	*next;
}					t_lexer;

typedef struct s_list
{
	char			*name;
	char			*content;
	struct s_list	*next;
}					t_list;

int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *s1, char *s2);
int					ft_lexer(char *line, t_lexer **lexer);
int					ft_isquote(int c);
int					ft_isspace(int c);
int					ft_operation(t_lexer **lexer);
void				ft_print_lexer(t_lexer **lexer);
int					ft_parse(t_lexer **lexer);
void				lexer_clear(t_lexer **lxr);
void				reset_quotes(char c, int *quoted, int *quoted2);
int					ft_convert(char *str, t_lexer *new);
t_lexer				*init_lexer(void);
void				ft_lexer_addback(t_lexer **lexer, t_lexer *new);
int					ft_token(t_lexer *lexer, char *str);
int					is_signal(char c);
int					init_word(char *str, int i, t_lexer *new);
void				change_quotes(char c, int *quoted, int *quoted2);
void				receive_signal(int id);
void 				ft_cd(char *cdcmd, t_list **envlist);
void				cd_action(char *cdcmd, t_list **envlist);
char				*change_pwd(t_list **envlist);
char 				*my_getenv(t_list *envlist, char *name, int flag);
char 				*clean_content(char *content);
int     			ft_strstr(char **env, char *find_to);
char				*ft_strjoin(char const *s1, char const *s2);
char 				**generate_my_own_enviroment(char **env);
void 				ft_export(t_list **envlist, char *str);
void 				ft_env(t_list **envlist);
void				ft_pwd(void);
void				ft_unset(t_list **envlist, char *unscmd);
void				generate_env_list(char **env, t_list **envlist);
t_list				*init_list(void);
char				*add_env_name(char **env, int i, int j);
char				*add_env_content(char **env, int i, int j);
void				ft_echo(char *echocmd, int flag, t_list *envlist);


#endif