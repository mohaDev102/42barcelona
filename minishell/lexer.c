
#include "minishell.h"

t_lexer	*init_lexer(void)
{
	t_lexer	*new;

	new = malloc(sizeof(t_lexer));
	if (!new)
		return (NULL);
	new->value = NULL;
	new->type = NOTH;
	new->next = NULL;
	return (new);
}

// lo que nos pasan: // echo "Hello" | cat -e > myfile

// lo que tendria que tener la struct: word word pipe word word ret_to word

// mira si hay | < > << >>
int	ft_token(t_lexer *lexer, char *str)
{
	int	i;

	i = 0;
	if (str[i] == PIPE_AS)
		lexer->type = PIPE;
	else if (str[i] == GREAT_AS && str[i + 1] == GREAT_AS)
		lexer->type = GREAT_L;
	else if (str[i] == LESS_AS && str[i + 1] == LESS_AS)
		lexer->type = LESS_L;
	else if (str[i] == LESS)
		lexer->type = LESS;
	else if (str[i] == GREAT)
		lexer->type = GREAT;
	else
		i = 1;
	return (i);
}

int	ft_space_or_null(char *str, int i)
{
	while (str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (-1);
	add_history(str);
	return (0);
}

t_lexer *ft_lexer_addback()
{
    
}

int	ft_lexer(char *line, t_lexer **lexer)
{
	int i;
	t_lexer *new;
	int checker;

	i = 0;
	if (ft_space_or_null(line, i) == -1)
		return (1);
	while (i < ft_strlen(line))
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			new = init_lexer();
			if (!new)
				return (1);
			// ft_lexer_add_back
			*lexer = ft_lexer_addback(*lexer, new);
			checker = ft_convert(ft_substr(line, i, ft_strlen(line)), new);
			if (!checker)
				return (1);
			i += checker;
			i++;
		}
	}
	return (0);
}