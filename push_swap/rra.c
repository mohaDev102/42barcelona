
#include "push_swap.h"

// void rra(t_stack **stack_a)
// {
//     t_stack *curr;
//     t_stack *aux;
//     t_stack *curr1;
//     curr = *stack_a;
//     curr1 = *stack_a;
//     aux = *stack_a;
//     curr = ft_lstlast(*stack_a);
//     // ft_lstadd_front(&aux, curr);
//     printf("%d", curr->value);
//     curr->next = aux;
//     curr1 = ft_lstlast(curr);
//     curr1->next = NULL;
//     // curr->next = NULL;
//     // curr = aux;
// }

void ft_lstadd_end(t_stack **lst, t_stack *new)
{
    if (*lst == NULL) // Si la lista está vacía
    {
        *lst = new;
        new->next = NULL; // Establecer el puntero next del nuevo nodo a NULL
    }
    else
    {
        t_stack *temp = *lst;
        while (temp->next != NULL) // Recorrer la lista hasta llegar al último nodo
        {
            temp = temp->next;
        }
        temp->next = new; // Establecer el puntero next del último nodo al nuevo nodo
        new->next = NULL; // Establecer el puntero next del nuevo nodo a NULL
    }
    // printf("%d", new->value);
}

// void rra(t_stack **stack_a)
// {
//     t_stack *curr;
//     t_stack *prev;
//     t_stack *last;

//     // Manejar el caso especial de una lista vacía o con un solo nodo
//     if (*stack_a == NULL || (*stack_a)->next == NULL)
//         return;

//     // Encuentra el penúltimo nodo de la lista
//     curr = *stack_a;
//     prev = NULL;
//     while (curr->next != NULL) {
//         prev = curr;
//         curr = curr->next;
//     }
//     // Mueve el último nodo al principio de la lista
//     last = curr;
//     last->next = *stack_a;  // Coloca el último nodo al principio
//     *stack_a = last;  // Actualiza el puntero de la lista
//     prev->next = NULL;  // Elimina el último nodo de su posición original
//     // ft_lstadd_front(&curr, last);
//     printf("Valor del primer elemento después de rra: %d\n", (*stack_a)->next->next->value);
// }

// void rra(t_stack **stack)
// {
//     t_stack *curr;
//     t_stack *prev;
//     t_stack *last;

//     curr = *stack;
//     prev = NULL;

//     // Encontrar el último elemento de la lista
//     while (curr->next != NULL)
//     {
//         prev = curr;
//         curr = curr->next;
//     }

//     // Guardar el último elemento
//     last = curr;

//     // Eliminar el último elemento de su posición original
//     if (prev != NULL)
//         prev->next = NULL;
//     else
//         *stack = NULL; // Si solo hay un elemento en la lista

//     // Agregar el último elemento al frente de la lista
//     last->next = *stack;
//     *stack = last;

// }

void rra(t_stack **stack_a)
{
    t_stack *curr;
    t_stack *prev;
    if (*stack_a == NULL || (*stack_a)->next == NULL) {
       return ;
    }
    curr = *stack_a;
    prev = NULL;
    while (curr->next != NULL) 
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = *stack_a;
    *stack_a = curr;
    write(1, "rra\n", 4);
}