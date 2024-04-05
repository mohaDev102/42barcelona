
#include "push_swap.h"

void sort_three(t_stack **stack)
{
    int first;
    int second;
    int third;
    first = (*stack)->index;
    second = (*stack)->next->index;
    third = (*stack)->next->next->index;
    if (first < second && second > third)
    {
        rra(stack);
        // sa(stack);
    }
    else if (first > second && first < third)
        sa(stack);
    else if (first < second && second > third)
    {
        rra(stack);
        sa(stack);
    }
    else if (first > second && first > third)
    {
        ra(stack);
        // sa(stack);
    }
    else if (first > second && first > third)
    {
        ra(stack);
        sa(stack);
    }
}