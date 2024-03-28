
#include "push_swap.h"

void ra(t_stack **stack_a)
{
     if (!(*stack_a) || !(*stack_a)->next)
        return;
    t_stack *first = *stack_a;
    t_stack *second = (*stack_a)->next;
    t_stack *last = first;

    while (last->next != NULL) 
    {
        last = last->next;
    }
    *stack_a = second;
    first->next = NULL;
    last->next = first;
    write(1, "ra\n", 3);
}