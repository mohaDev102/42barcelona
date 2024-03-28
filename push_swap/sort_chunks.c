
#include "push_swap.h"

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	index;
	int	min_int;
	int	times;

	while (stack_a->size)
	{
		times = 0;
		min_int = ft_find_min_int(stack_a);
		while (times++ < chunk_size)
		{
			min_int = ft_find_next_min_int(stack_a, min_int);
			if (times == chunk_size / 2)
				stack_a->middle = min_int;
		}
		times = 0;
		while (times++ < chunk_size)
		{
			index = ft_get_min_int_index(stack_a, min_int);
			ft_insert_int_to_top(stack_a, 'a', stack_a->stack[index]);
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->middle)
				ft_do_rotate(stack_b, 'b');
		}
	}
	ft_push_b_to_a(stack_a, stack_b);
}

void ft_do_rotate(t_stack *stack) {
    if (stack->size > 0) {
        int first = stack->stack[0];
        for (int i = 0; i < stack->size - 1; i++) {
            stack->stack[i] = stack->stack[i + 1];
        }
        stack->stack[stack->size - 1] = first;
    }
}

int ft_get_min_int_index(t_stack *stack, int min_int) {
    for (int i = 0; i < stack->size; i++) {
        if (stack->stack[i] == min_int) {
            return i;
        }
    }
    return -1; // En caso de no encontrar el valor
}

int ft_find_next_min_int(t_stack *stack, int current_min) {
    int next_min = INT_MAX;
    for (int i = 0; i < stack->size; i++) {
        if (stack->stack[i] > current_min && stack->stack[i] < next_min) {
            next_min = stack->stack[i];
        }
    }
    return next_min;
}

int ft_find_min_int(t_stack *stack) {
    int min_int = INT_MAX;
    for (int i = 0; i < stack->size; i++) {
        if (stack->stack[i] < min_int) {
            min_int = stack->stack[i];
        }
    }
    return min_int;
}

void ft_rotate(t_stack **stack) {
    if (*stack == NULL || (*stack)->next == NULL) return;
    
    t_stack *first = *stack;
    t_stack *current = *stack;
    
    while (current->next != NULL) {
        current = current->next;
    }
    
    *stack = first->next; // El segundo nodo ahora es el primero
    first->next = NULL; // El antiguo primer nodo ahora es el último
    current->next = first; // Enlazar el antiguo primer nodo al final
}

void ft_push(t_stack **src, t_stack **dest) {
    if (*src == NULL) return;
    t_stack *temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}