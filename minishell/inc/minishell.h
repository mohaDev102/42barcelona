/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:56:42 by mel-atta          #+#    #+#             */
/*   Updated: 2024/05/11 18:36:15 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif
# include <stdio.h>
# include "../readline/history.h"
# include "../readline/readline.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include	<fcntl.h>
int					g_error;

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
} t_type_redir;

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
	int fd[2];
	pid_t *pid;
	int n_commands;
	int std_in;
	int std_out;
}					t_pipe;

int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *c);
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
int	ft_operation(t_lexer **lexer, t_cmd **cmd, char *env[]);
void				ft_print_lexer(t_lexer **lexer);
int					ft_parse(t_cmd **commands, t_lexer *lexer);
void	lexer_clear(t_cmd **cmd, t_lexer **lxr);
void				reset_quotes(char c, int *quoted, int *quoted2);
int					ft_convert(char *str, t_lexer *new);
t_lexer				*init_lexer(void);
void				ft_lexer_addback(t_lexer **lexer, t_lexer *new);
int					ft_token(t_lexer *lexer, char *str);
int					is_signal(char c);
int					init_word(char *str, int i, t_lexer *new);
void				change_quotes(char c, int *quoted, int *quoted2);
void				receive_signal(int id);
int					ft_count_lexer(t_lexer *lexer);
t_cmd				*init_parser(void);
void				ft_add_cmd_back(t_cmd **command, t_cmd *new);
int					create_cmd(t_lexer **lexer, t_cmd **cmd, int i);
int					add_cmd(t_lexer **lexer, t_cmd **cmd, t_redir **redir);
void ft_print_parser(t_cmd **cmd);
void	ft_parser_addback(t_redir **redir, t_redir *new);
t_redir *redir_lstlast(t_redir *redir);
int is_redirect(t_lexer **lexer, t_redir **redir);
void ft_print_redir(t_redir **redir);
char	**ft_free(char **mat, int i);
void parser_free(t_cmd **cmd);
void free_cmd_list(t_cmd *cmd);
void her_doc(t_cmd *cmd, char **env);
int executor(t_cmd **cmd, t_lexer **lexer, char **env);
int ft_count_args(t_lexer *aux);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif