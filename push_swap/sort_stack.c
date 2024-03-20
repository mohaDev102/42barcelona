
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


void sort_stack(t_stack **stack_a)
{
    // (void) **stack_a;
    int len;
    // printf("\nordenacion de stack_a\n");
    // printf("%d", ft_lstsize(stack_a));
    len = ft_lstsize(stack_a);
    if (len <= 3)
    {
        //sa();
        sort_three(stack_a);
    }
    else if (len > 3 && len <= 5)
    {
        // sa();
        // pb();
        // sort_five();
    }
    else if (len > 5)
    {
        // hacer el chunks
    }
    // control de cuantos numeros son
    // ponerles indices
    // en funcion de cuantos numeros son llamos a una funcion o otra
}