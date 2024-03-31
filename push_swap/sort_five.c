
#include "push_swap.h"

int hypothetical_position_decider(t_stack *stack_a, int value_b_top)
{
    if (!stack_a)
    {
        // Si stack_a está vacío, siempre deberíamos reintegrar el elemento de stack_b.
        return 1;
    }

    // Asigna min_value_a y max_value_a basado en los nodos de stack_a
    int min_value_a = stack_a->value; // El valor del primer nodo se considera el mínimo inicialmente.
    int max_value_a = stack_a->value; // El valor del primer nodo también se considera el máximo inicialmente.

    t_stack *current = stack_a;
    while (current != NULL)
    {
        if (current->value < min_value_a)
        {
            min_value_a = current->value; // Encuentra el valor mínimo actual en stack_a
        }
        if (current->value > max_value_a)
        {
            max_value_a = current->value; // Encuentra el valor máximo actual en stack_a
        }
        current = current->next; // Avanza al siguiente nodo
    }

    // La lógica para decidir si el valor de stack_b debe ir al inicio de stack_a
    // basada en comparaciones con el mínimo y máximo de stack_a.
    if (value_b_top > max_value_a)
    {
        // Si el valor del top de stack_b es mayor que el máximo de stack_a,
        // entonces debería ser reintegrado al final de stack_a, indicamos false.
        return 0;
    }
    else
    {
        // En cualquier otro caso, reintegramos al inicio por simplicidad.
        // Esta es una simplificación; la lógica detallada dependerá de tu enfoque.
        return 1;
    }
}

void finalize_sort(t_stack **stack_a)
{
    // Verifica si los dos primeros elementos de stack_a están desordenados y los intercambia si es necesario.
    if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
    {
        sa(stack_a); // Intercambia los dos primeros elementos si están en el orden incorrecto.
    }
}

int length_of_stack(t_stack *stack)
{
    int length = 0;
    while (stack != NULL)
    {
        stack = stack->next;
        length++;
    }
    return length;
}

void move_smallest_two_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int smallest_index = INT_MAX;
    int second_smallest_index = INT_MAX;
    t_stack *current = *stack_a;

    // Encontrar los índices de los dos elementos más pequeños
    while (current != NULL)
    {
        if (current->index < smallest_index)
        {
            second_smallest_index = smallest_index;
            smallest_index = current->index;
        }
        else if (current->index < second_smallest_index && current->index != smallest_index)
        {
            second_smallest_index = current->index;
        }
        current = current->next;
    }

    // Ahora, necesitamos movernos a través de stack_a para encontrar y mover estos elementos a stack_b
    // Esto se hará en dos pasos, asegurando primero mover el elemento con el segundo índice más pequeño y luego el más pequeño.
    for (int i = 0; i < 2; i++)
    {
        current = *stack_a;
        int target_index = (i == 0) ? second_smallest_index : smallest_index;
        int moves = 0;

        while (current != NULL && current->index != target_index)
        {
            current = current->next;
            moves++;
        }

        // Decide si es más corto rotar o rotar inversamente.
        if (moves < length_of_stack(*stack_a) / 2)
        {
            while ((*stack_a)->index != target_index)
            {
                ra(stack_a); // Asume que tienes una función ra que ajusta el puntero de stack_a
            }
        }
        else
        {
            while ((*stack_a)->index != target_index)
            {
                rra(stack_a); // Asume que tienes una función rra que ajusta el puntero de stack_a
            }
        }
        pb(stack_a, stack_b); // Asume que tienes una función pb que mueve el elemento de stack_a a stack_b
    }
}

int find_position_in_a(t_stack *stack_a, int b_index)
{
    int pos = 0;
    t_stack *current = stack_a;

    // Si stack_a está vacío o el valor de b es menor que el primer elemento de a,
    // entonces b debería insertarse al principio.
    if (!current || b_index < current->value)
    {
        return 0;
    }

    // Itera sobre stack_a para encontrar la posición correcta
    while (current->next && b_index > current->next->value)
    {
        current = current->next;
        pos++;
    }

    // Devuelve la posición donde b debería insertarse.
    // Si b es mayor que todos los elementos en a, esta será la posición al final de a.
    return pos + 1;
}

void insert_from_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b != NULL)
    {
        // Asumiremos que tienes una función que puede determinar la posición correcta en stack_a para el elemento top de stack_b
        int position_in_a = find_position_in_a(*stack_a, (*stack_b)->index);
        int stack_a_length = length_of_stack(*stack_a);

        // Decidir si usar rotaciones o rotaciones inversas basado en la posición
        if (position_in_a <= stack_a_length / 2)
        {
            while (position_in_a-- > 0)
            {
                ra(stack_a); // Rotar stack_a para llevar la posición correcta al tope
                // position_in_a--;
            }
        }
        else
        {
            int reverse_moves = stack_a_length - position_in_a;
            while (reverse_moves-- > 0)
            {
                rra(stack_a); // Rotar inversamente stack_a para llevar la posición correcta al tope
                // position_in_a++;
            }
        }

        pa(stack_a, stack_b); // Mover el elemento top de stack_b a stack_a

        // Nota: Esta implementación es simplificada. Puede requerir ajustes para optimizar el número de movimientos.
    }
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    assign_indices(stack_a);
    // move_smallest_two_to_b(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value)
        ra(stack_a);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    sort_three(stack_a);
    pa(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value)
    {
        ra(stack_a);
        pa(stack_a, stack_b);
    }
    pa(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value && 
        (*stack_a)->value > (*stack_a)->next->next->next->value)
    {
        //pa(stack_a, stack_b);
        ra(stack_a);
    }
    // else

    // insert_from_b_to_a(stack_a, stack_b);
    // pa(stack_a, stack_b);
    // finalize_sort(stack_a);
    // while (*stack_b != NULL)
    // {
    //     if ((*stack_b)->value < (*stack_a)->value) {
    //         pa(stack_a, stack_b); // Mueve stack_b->value a stack_a
    //         ra(stack_a); // Rota stack_a para ajustar la posición
    //     }
    //     // Si stack_b->value debe ir después del último elemento en stack_a
    //     else if ((*stack_b)->value > (*stack_a)->value) {
    //         pa(stack_a, stack_b); // Mueve stack_b->value a stack_a sin rotar, necesita más lógica aquí
    //     }
    //     else {
    //         // En caso de que stack_b->value deba ir en medio, requeriría más lógica para determinar la posición exacta
    //         pa(stack_a, stack_b); // Simplificación, esto necesita una lógica más precisa
    //     }

    //     // if (hypothetical_position_decider(*stack_a, (*stack_b)->value)) {
    //     //     ra(stack_a); // Coloca el top de stack_a en la posición correcta antes de pa
    //     // }
    //     // if ((*stack_b)->value < (*stack_b)->next->value)
    //     //     ra(stack_a);
    //     // pa(stack_a, stack_b);
    //     // if ((*stack_a)->value > (*stack_a)->next->value) {
    //     //     sa(stack_a); // Ajusta si el último elemento reintegrado necesita intercambio
    //     // }
    //     // printf("ef");
    // }
}