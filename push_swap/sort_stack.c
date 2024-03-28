
#include "push_swap.h"

int ft_lstsize(t_stack **stack)
{
    int i = 0;
    t_stack *curr;

    curr = *stack;
    while (curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    return (i);
}


void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    // (void) **stack_a;
    // t_stack **stack_b;
    int len;
    len = ft_lstsize(stack_a);
    if (len < 3)
        sa(stack_a);
    else if (len == 3)
        sort_three(stack_a);
    else if (len <= 120)
    {
        (*stack_a)->size = len;
        ft_chunk_sort(*stack_a, *stack_b, 18);
    }
    else
    {
        (*stack_a)->size = len;
        ft_chunk_sort(*stack_a, *stack_b, 50);
    }
}