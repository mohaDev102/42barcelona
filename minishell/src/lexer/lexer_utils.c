#include "../../inc/minishell.h"

int	ft_isspace(int c)
{
	if (c == 32 || c == '\t' || c == '\n' || c == '\f' || c == '\v'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

int	is_signal(char c)
{
	if (c == PIPE_AS || c == GREAT_AS || c == LESS_AS)
		return (1);
	return (0);
}

void	ft_print_lexer(t_lexer **lexer)
{
	t_lexer	*aux;

	aux = *lexer;
	while (aux != NULL)
	{
		printf("\ntexto: %s tipo:  %d\n", aux->value, aux->type);
		aux = aux->next;
	}
}

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
