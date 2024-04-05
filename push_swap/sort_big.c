
#include "push_swap.h"


void sort_nums(t_stack **stack_a, t_stack **stack_b, int bit)
{
    int num;
    int i;
    int size;

    i = 0;
    size = ft_lstsize(stack_a);
    while (i < size)
    {
        num = (*stack_a)->index;
        if ((num >> bit) & 1)
            ra(stack_a);
        else
            pb(stack_a, stack_b);
        i++;
    }
}

void sort_big(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int max_num;
    int max_bits;
    int i;

    size = ft_lstsize(stack_a);
    max_num = size - 1;
    max_bits = 0;
    i = 0;
    while (max_num)
    {
        max_num = max_num >> 1;
        max_bits++;
    }
    while (i < max_bits)
    {
        sort_nums(stack_a, stack_b, i);
        while (*stack_b != NULL)
            pa(stack_a, stack_b);
        i++;
    }
}