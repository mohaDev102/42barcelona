
#include "push_swap.h"

void pb(t_stack **a, t_stack **b)
{
    t_stack *top_of_a;

    if (*a == NULL) {
        return; // La pila A está vacía, no hay nada que mover
    }
    top_of_a = *a; // Guardar el elemento superior de A
    *a = (*a)->next; // Actualizar la cabeza de A al segundo elemento
    top_of_a->next = NULL; // Desconectar el antiguo top de A del resto
    ft_lstadd_front(b, top_of_a); // Añadir el antiguo top de A al principio de B
}