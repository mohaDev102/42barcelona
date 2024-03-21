
#include "push_swap.h"

void rra(t_stack **stack_a)
{
    t_stack *curr;
    t_stack *aux;
    curr = *stack_a;
    aux = *stack_a;
    ft_lstaddend(&aux, curr);
    curr = ft_lstlast(aux);
    ft_lstadd_front(&aux, curr);
    // curr = aux;
}