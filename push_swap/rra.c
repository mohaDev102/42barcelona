
#include "push_swap.h"

void rra(t_stack **stack_a)
{
    t_stack *curr;
    t_stack *prev;
    if (*stack_a == NULL || (*stack_a)->next == NULL)
       return ;
    curr = *stack_a;
    prev = NULL;
    while (curr->next != NULL) 
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = *stack_a;
    *stack_a = curr;
    write(1, "rra\n", 4);
}