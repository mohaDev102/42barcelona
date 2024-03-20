
#include "push_swap.h"

void sort_three(t_stack **stack)
{
    t_stack *curr;

    curr = *stack;
    if (curr->value > curr->next->value)
        sa(&curr);
    else
        rra(&curr);

}