/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alounici <alounici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:56:42 by mel-atta          #+#    #+#             */
/*   Updated: 2024/06/13 16:24:09 by alounici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif
# include <stdio.h>
# include "../readline/readline.h"
# include "../readline/history.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <termios.h>
#include <setjmp.h>

# define PIPE_AS 124
# define LESS_AS 60
# define GREAT_AS 62

typedef enum s_type
{
	NOTH = 0,
	PIPE,
	LESS,
	LESS_L,
	GREAT,
	GREAT_L,
}					t_type;

typedef enum s_type_redir
{
	NOTH_REDIR = 0,
	OUTFILE,
	APPEND,
	HERDOC,
	INFILE
}					t_type_redir;

typedef struct s_lexer
{
	char			*value;
	t_type			type;
	struct s_lexer	*next;
}					t_lexer;

typedef struct s_redir
{
	t_type_redir	type;
	char			*file;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redir;
	struct s_cmd	*next; 
}					t_cmd;

typedef struct s_pipe
{
	int				fd[2];
	pid_t			*pid;
	int				n_commands;
	int				std_in;
	int				std_out;
}					t_pipe;

typedef struct s_list
{
	char			*name;
	char			*content;
	struct s_list	*next;
}					t_list;

// static struct 
// {
//     sigjmp_buf jmpbuf;
//     struct termios saved_term_attr;
// } global_context;

int	ft_isalpha(int c);
char *ft_realloc(char *str, int i);
int					ft_isprint(int c);
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
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
t_list				*ft_lstlast(t_list *lst);
int					ft_operation(t_lexer **lexer, t_cmd **cmd, char *env[], t_list **envlist);
void				ft_print_lexer(t_lexer **lexer);
int					ft_parse(t_cmd **commands, t_lexer *lexer);
void				lexer_clear(t_cmd **cmd, t_lexer **lxr);
void				reset_quotes(char c, int *quoted, int *quoted2);
int					ft_convert(char *str, t_lexer *new, int i);
t_lexer				*init_lexer(void);
void				ft_lexer_addback(t_lexer **lexer, t_lexer *new);
int					ft_token(t_lexer *lexer, char *str, int i);
int					is_signal(char c);
int					init_word(char *str, int i, t_lexer *new);
void				change_quotes(char c, int *quoted, int *quoted2);
int				receive_signal(int id, int fd);
void				ft_cd(char *cdcmd, t_list **envlist);
void				cd_action(char *cdcmd, t_list **envlist);
char				*change_pwd(t_list **envlist);
char	*change_oldpwd(t_list **envlist);
char				*my_getenv(t_list *envlist, char *name, int flag);
char				*clean_content(char *content);
int					ft_strstr(char **env, char *find_to);
char				*ft_strjoin(char const *s1, char const *s2);
char 				**generate_my_own_enviroment(char **env);
void 				ft_export(t_list **envlist, char *str);
void 	ft_export_alone(t_list **envlist);
void 				ft_env(t_list **envlist);
char				**generate_my_own_enviroment(char **env);
void				ft_export(t_list **envlist, char *str);
void				ft_env(t_list **envlist);
void				ft_pwd(void);
void				ft_unset(t_list **envlist, char *unscmd);
void				generate_env_list(char **env, t_list **envlist);
t_list				*init_list(void);
t_list	*ft_list(char **env);
char				*add_env_name(char **env, int i, int j);
char				*add_env_content(char **env, int i, int j);
void				ft_echo(char *echocmd, int flag, t_list *envlist);
int 				expandor(t_cmd *cmd, t_list **envlist);
char *expand(char **str, int j, t_list **envlist);
char	*handle_quote(char *str, int i);
char *clean_str(char *str, char c, int quote);
char *extract_var_name(char *str, int i);
char *last_exit(void);
int	exit_status(int value);
char **copy_env(char **env);
int    is_buildins(t_cmd **cmd, t_list **envlist, t_pipe *data);
int    is_echo(t_cmd **tmp, t_list *envlist);
void ft_exit(char **args);
void    print_export_error(char *str);
void   print_exit_error(char *str, int neg);
char	*extract_env_content(char *str);
char	*extract_env_name(char *str);
// void   print_exit_error(char *str);
void    print_export_error(char *str);
char *clean_exit_space(char *str);
// char *clean_space(char *str, int i);
int check_quote_number(char *str, char c);
char **join_var_name(char *str, int i);
int	quote_found(char **str, int j, int i);
int exec_echo_n(int nindex, char **args, t_list *envlist);
void exec_echo(int nindex, char **args, t_list *envlist);
int ft_maplen(char **str);
char	**ft_mapjoin(char **map, char *str);
char	*ft_substrecho(char const *s, unsigned int start, size_t len);
char	**ft_joinmap(char **map, char *str);
void ft_tilde(t_list *envlist);

int					ft_count_lexer(t_lexer *lexer);
t_cmd				*init_parser(void);
void				ft_add_cmd_back(t_cmd **command, t_cmd *new);
int					create_cmd(t_lexer **lexer, t_cmd **cmd, int i);
int					add_cmd(t_lexer **lexer, t_cmd **cmd, t_redir **redir);
void				ft_print_parser(t_cmd **cmd);
void				ft_parser_addback(t_redir **redir, t_redir *new);
t_redir				*redir_lstlast(t_redir *redir);
int					is_redirect(t_lexer **lexer, t_redir **redir);
void				ft_print_redir(t_redir **redir);
char				**ft_free(char **mat, int i);
void				parser_free(t_cmd **cmd);
void				free_cmd_list(t_cmd *cmd);
void				her_doc(t_cmd *cmd);
int					executor(t_cmd **cmd, t_list **envlist, char *myenv[]);
int					ft_count_args(t_lexer *aux);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putstr_fd(char *s, int fd);
void				infile_herdoc(t_redir *aux, int fd);
void				outfile(t_redir *aux, int fd);
void				append(t_redir *aux, int fd);
void				ft_error_cmd(t_cmd **cmd, char *msg);
int					parser_lstsize(t_cmd *lst);
void				redirections(t_cmd *cmd, t_pipe data);
t_pipe				*ft_pipes(t_cmd **cmd);
int check_error(t_lexer *lexer);
void	close_pipe(int in, int out);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *name, char *content);
void print_limit_exit(char *str);
int	is_build(t_cmd *cmd);
char	*extract_env_name(char *str);
char	*extract_env_content(char *str);
void   print_notdigit_exit(char *str);
int     ft_isalpha(int c);
char	*ft_strchr(const char *str, int c);
void	*ft_memchr(const void *s, int c, size_t n);
void search_path(char **paths, t_cmd **cmd, char *env[]);
void free_env(char **env);
void free_pipes(t_pipe *data);
void free_envlist(t_list *envlist);
void free_split(char **split);
char	*ft_getenv(char *name, char *env[]);
void	free_split(char **split);
void	wait_children(t_pipe *info, int *exit);
#endif