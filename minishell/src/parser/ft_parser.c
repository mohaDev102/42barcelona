
#include "../../inc/minishell.h"

t_lexer *ft_last_lexer(t_lexer **lexer)
{
    t_lexer *aux;
    aux = *lexer;
    while (aux != NULL && aux->next != NULL)
    {
        aux = aux->next;
    }
    return (aux);
}

int check_pipes(t_lexer **lexer)
{
    if ((*lexer)->type == 1 || ft_last_lexer(lexer)->type == 1)
        return (1);
    return (0);
}

void	lexer_clear(t_lexer **lxr)
{
	t_lexer	*tmp;

	while (*lxr != NULL)
	{
		tmp = *lxr;
		*lxr = (*lxr)->next;
		free(tmp->value);
		free(tmp);
	}
}

void ft_error(t_lexer **lexer)
{
    if ((*lexer)->type == 1 || ft_last_lexer(lexer)->type == 1)
        write(1, "bash: syntax error near unexpected token |\n", 44);
    else if (ft_last_lexer(lexer)->type == 2 || ft_last_lexer(lexer)->type == 3 || ft_last_lexer(lexer)->type == 4 || ft_last_lexer(lexer)->type == 5)
        write(1, "bash: syntax error near unexpected token 'newline'\n", 52);
}

// hay que pasarle la estruct para el cmd
// hacer la struct para que se guarde las parablas (comandos) y en el redirect: >> | si es que hay

int ft_parse(t_lexer **lexer)
{
    t_lexer *aux;
    aux = *lexer;
    if (check_pipes(lexer) || ft_last_lexer(lexer)->type == 1 ||
        ft_last_lexer(lexer)->type == 1 || 
        ft_last_lexer(lexer)->type == 2
        || ft_last_lexer(lexer)->type == 3 || 
        ft_last_lexer(lexer)->type == 4 || 
        ft_last_lexer(lexer)->type == 5)
    {
        ft_error(lexer);
    }
    return (0);
}