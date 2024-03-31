
#include "push_swap.h"

void sort_three(t_stack **stack)
{
    int first;
    int second;
    int third;

    first = (*stack)->value;
    second = (*stack)->next->value;
    third = (*stack)->next->next->value;
    if (first < second && second > third && first < third)
    {
        sa(stack);
        ra(stack);
    }
    else if (first > second && second > third && first > third)
    {
        ra(stack);
        sa(stack);
    } else if (first > second && second < third && first < third)
        sa(stack);
    else if (first < second && second > third && first > third)
        rra(stack);
    else if (first > second && second < third && first > third)
        ra(stack);
}