
#include "push_swap.h"

void assign_indices(t_stack **stack) {
    t_stack *current = *stack;
    int index = 0; // Comienza en 0 e incrementa por cada nodo

    while (current != NULL) {
        current->index = index; // Asigna el índice actual al nodo
        current = current->next; // Avanza al siguiente nodo
        index++; // Incrementa el índice para el próximo nodo
    }
}

int find_hold_first(t_stack *stack, int start_range, int end_range) {
    int index = 0;
    while (stack) {
        if (stack->index >= start_range && stack->index <= end_range) {
            return index; // Retorna el índice en la pila, que representa el número de movimientos de 'ra' necesarios.
        }
        stack = stack->next;
        index++;
    }
    return -1; // Retorna -1 si no se encuentra un valor con índice en el rango especificado.
}

int find_hold_second(t_stack *stack, int start_range, int end_range) {
    int index = 0;
    int hold_second_position = -1; // Almacena la posición desde el fondo de la pila para el 'hold_second'.
    t_stack *current = stack;
    
    // Recorremos la pila una vez para contar su tamaño.
    int stack_length = 0;
    while (current) {
        current = current->next;
        stack_length++;
    }

    // Restablecemos 'current' al principio de la pila y buscamos 'hold_second'.
    current = stack;
    while (current) {
        if (current->index >= start_range && current->index <= end_range) {
            hold_second_position = stack_length - index - 1;
            // En este punto, podemos decidir si continuar buscando para obtener el 'hold_second'
            // más cercano al fondo de la pila, o retornar el primero que encontremos.
        }
        current = current->next;
        index++;
    }
    return hold_second_position; // Posición desde el fondo para 'hold_second'.
}

int find_max(t_stack *stack) {
    int max_index_value = -1;
    int max_position = -1;
    int position = 0;

    while (stack) {
        if (stack->index > max_index_value) {
            max_index_value = stack->index;
            max_position = position;
        }
        stack = stack->next;
        position++;
    }
    return max_position; // Posición del nodo con el mayor índice.
}

int stack_size(t_stack *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

void move_to_top(t_stack **stack, int use_ra, int num_moves) {
    while (num_moves-- > 0) {
        if (use_ra) {
            ra(stack);
        } else {
            rra(stack);
        }
    }
}

void sort_stack_100(t_stack **stack_a, t_stack **stack_b)
{
    for (int i = 0; i < 100; i++) {
        int start_range = i * 5;
        int end_range = (i + 1) * 5 - 1;
        int numbers_moved = 0;

        while (numbers_moved < 5) {
            int hold_first = find_hold_first(*stack_a, start_range, end_range);
            int hold_second = find_hold_second(*stack_a, start_range, end_range);
            int size_a = stack_size(*stack_a);

            // Decide whether to use ra or rra based on hold_first and hold_second
            if (hold_first <= size_a / 2) {
                move_to_top(stack_a, 1, hold_first);
            } else {
                move_to_top(stack_a, 0, size_a - hold_second);
            }

            pb(stack_a, stack_b);
            numbers_moved++;
        }
    }

    // Once all chunks are moved to stack_b, sort them back into stack_a
    while (stack_size(*stack_b) > 0) {
        int max_index = find_max(*stack_b);
        int size_b = stack_size(*stack_b);
        move_to_top(stack_b, max_index <= size_b / 2, max_index);
        pa(stack_b, stack_a);
    }
}