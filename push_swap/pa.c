
#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *top_of_b;

    if (*b == NULL) {
        return; // La pila B está vacía, no hay nada que mover
    }
    top_of_b = *b; // Guardar el elemento superior de B
    *b = (*b)->next; // Actualizar la cabeza de B al segundo elemento
    top_of_b->next = NULL; // Desconectar el antiguo top de B del resto

    ft_lstadd_front(a, top_of_b); // Añadir el antiguo top de B al principio de A
}