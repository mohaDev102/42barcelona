
#include "push_swap.c"

void rra(t_stack **stack_a)
{
    t_stack *curr;
    t_stack *aux;
    int tmp;
    curr = *stack_a;
    
    tmp = curr->value;
    // funcion para saber la ultima posicion
    curr->value  = ft_lstlast(curr);
    curr->next->value = tmp;
}