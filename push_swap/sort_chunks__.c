
#include "push_swap.h"

void	assign_indices(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		index++;
	}
}

void init_stack(t_stack **stack_a)
{
    t_stack *curr;

    curr = *stack_a;
    while (curr != NULL)
    {
        curr->index = -1;
        curr = curr->next;
    }
}

void	assign_index(t_stack **stack)
{
	 t_stack *current;
    t_stack *temp;
    int index = 0;
    int min_value = INT_MAX;

    // Buscamos el valor mínimo en la pila
    temp = *stack;
    while (temp != NULL) {
        if (temp->value < min_value)
            min_value = temp->value;
        temp = temp->next;
    }

    // Iteramos sobre la pila para asignar los índices basados en los valores
    current = *stack;
    while (current != NULL) {
        if (current->value == min_value) {
            current->index = index++;
        }
        current = current->next;
    }

    // Incrementamos el valor mínimo para asignar los índices a los siguientes elementos
    min_value++;

    // Asignamos índices a los demás elementos de la pila
    index = 0;
    while (index < ft_lstsize((stack))) {
        current = *stack;
        while (current != NULL) {
            if (current->index == -1) {
                if (current->value == min_value) {
                    current->index = index++;
                }
            }
            current = current->next;
        }
        min_value++;
    }
}

int	find_hold_first(t_stack *stack, int start_range, int end_range)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->index >= start_range && stack->index <= end_range)
		{
			return (index);
		}
		stack = stack->next;
		index++;
	}
	return (-1); // Retorna
}

int	find_hold_second(t_stack *stack, int start_range, int end_range)
{
	int		index;
	t_stack	*current;
	int		stack_length;
	int		hold_second_position;

	index = 0;
	hold_second_position = -1;
	// Almacena la posición desde el fondo de la pila para el 'hold_second'.
	current = stack;
	// Recorremos la pila una vez para contar su tamaño.
	stack_length = 0;
	while (current)
	{
		current = current->next;
		stack_length++;
	}
	// Restablecemos 'current' al principio de la pila y buscamos 'hold_second'.
	current = stack;
	while (current)
	{
		if (current->index >= start_range && current->index <= end_range)
		{
			hold_second_position = stack_length - index - 1;
		}
		current = current->next;
		index++;
	}
	return (hold_second_position);
	// Posición desde el fondo para 'hold_second'.
}

int	find_max(t_stack *stack)
{
	int	max_index_value;
	int	max_position;
	int	position;

	max_index_value = -1;
	max_position = -1;
	position = 0;
	while (stack)
	{
		if (stack->index > max_index_value)
		{
			max_index_value = stack->index;
			max_position = position;
		}
		stack = stack->next;
		position++;
	}
	return (max_position); // Posición del nodo con el mayor índice.
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	move_to_top(t_stack **stack, int use_ra, int num_moves)
{
	while (num_moves-- > 0)
	{
		if (use_ra)
		{
			ra(stack);
		}
		else
		{
			rra(stack);
		}
	}
}

void	sort_stack_100(t_stack **stack_a, t_stack **stack_b)
{
	for (int i = 0; i < 100; i++)
	{
		int start_range = i * 5;
		int end_range = (i + 1) * 5 - 1;
		int numbers_moved = 0;

		while (numbers_moved < 5)
		{
			int hold_first = find_hold_first(*stack_a, start_range, end_range);
			int hold_second = find_hold_second(*stack_a, start_range,
					end_range);
			int size_a = stack_size(*stack_a);

			// Decide whether to use ra or rra based on hold_first and hold_second
			if (hold_first <= size_a / 2)
			{
				move_to_top(stack_a, 1, hold_first);
			}
			else
			{
				move_to_top(stack_a, 0, size_a - hold_second);
			}

			pb(stack_a, stack_b);
			numbers_moved++;
		}
	}

	// Once all chunks are moved to stack_b, sort them back into stack_a
	while (stack_size(*stack_b) > 0)
	{
		int max_index = find_max(*stack_b);
		int size_b = stack_size(*stack_b);
		move_to_top(stack_b, max_index <= size_b / 2, max_index);
		pa(stack_b, stack_a);
	}
}