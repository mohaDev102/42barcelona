
#include "push_swap.h"

void sa(t_stack **stack_a)
{
    t_stack *curr;
    t_stack *aux;
    int tmp;

    aux = *stack_a;
    curr = *stack_a;
    tmp = curr->value;
    curr->value = curr->next->value;
    curr->next->value = tmp;
    curr = aux;
    write(1, "sa\n", 3);
}