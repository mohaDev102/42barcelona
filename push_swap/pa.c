
#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *top_of_b;

    if (*b == NULL) {
        return; 
    }
    top_of_b = *b;
    *b = (*b)->next;
    top_of_b->next = NULL;

    ft_lstadd_front(a, top_of_b);
    write(1, "pa\n", 3);
}