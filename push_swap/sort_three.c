
#include "push_swap.h"

void sort_three(t_stack **stack)
{
    // t_stack *curr;

    // curr = *stack;
    // añadir todos los posibles casos 3 numeros no ordenados 
    // hacer funcion ra
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
    else if ((*stack)->value < (*stack)->next->value)
        rra(stack); //first > second && second > third && first > third
    else if ((*stack)->value > (*stack)->next->value && (*stack)->next->value > (*stack)->next->next->value
        && (*stack)->value > (*stack)->next->next->value)
    {
        rra(stack);
        sa(stack);
    }

}