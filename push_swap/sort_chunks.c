
#include "push_swap.h"

int is_empty(t_stack *stack) 
{
    return stack == NULL;
}

void	bubble_sort(int *array, int n)
{
	int	temp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				// Intercambia los elementos
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int	*create_and_sort_values_array(t_stack *stack, int size)
{
	int	*values;
	int	i;

	values = malloc(size * sizeof(int));
	i = 0;
	while (stack)
	{
		values[i++] = stack->value;
		stack = stack->next;
	}
	bubble_sort(values, size);
	return (values);
}

void	assign_indices(t_stack **stack)
{
	int		*sorted_values;
	t_stack	*current_node;

	int size = ft_lstsize(stack); // Asume que tienes esta función definida
	sorted_values = create_and_sort_values_array(*stack, size);
	// assign_index(stack, sorted_values, size);
	current_node = *stack;
	while (current_node)
	{
		// Encuentra el índice de su valor en la matriz ordenada
		for (int i = 0; i < size; i++)
		{
			if (sorted_values[i] == current_node->value)
			{
				current_node->index = i;
				// break ;
					// Encuentra el primer valor correspondiente y rompe el ciclo
			}
		}
		current_node = current_node->next;
	}
	free(sorted_values); // Limpia la memoria
}

// void	sort_chunks(t_stack **stack_a, t_stack **stack_b, int num_chunks)
// {
// 	int size = ft_lstsize(stack_a);
//     int chunk_size = size / num_chunks;
//     int max_chunk_index = chunk_size;
    
//     for (int i = 0; i < num_chunks; ++i) {
//         int count = 0; // Contador para saber cuántos números hemos movido en este chunk.
//         while (count < chunk_size) {
//             if ((*stack_a)->index < max_chunk_index) {
//                 pb(stack_a, stack_b);
//                 count++;
//             } else {
//                 ra(stack_a);
//             }
//         }
//         max_chunk_index += chunk_size;
//     }

//     // Este bucle es para manejar cualquier número restante en caso de que el total no sea divisible exactamente por num_chunks.
//     while (ft_lstsize(stack_a) > 0) {
//         pa(stack_a, stack_b);
//     }
// }




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

void sort_chunks(t_stack **stack_a, t_stack **stack_b, int num_chunks) {
    int size = ft_lstsize(stack_a); // Asume que esta función devuelve el tamaño de la pila
    int chunk_size = size / num_chunks;
    int remaining_elements = size;

    // Asigna índices a los elementos de la pila si aún no se ha hecho
    assign_indices(stack_a); // Asume que esta función asigna un índice ordenado a cada elemento

    while (num_chunks > 0) {
        int elements_moved = 0;
        while (elements_moved < chunk_size && remaining_elements > 0) {
            // Selecciona y mueve el elemento adecuado de `stack_a` a `stack_b`
            smart_move(stack_a); // Adapta esta función para seleccionar inteligentemente qué elemento mover
            pb(stack_a, stack_b); // Mueve el elemento superior de `stack_a` a `stack_b`
            elements_moved++;
            remaining_elements--;
        }
        num_chunks--;
    }

    // Una vez que todos los chunks se han movido a `stack_b`, los reinsertamos en `stack_a` en el orden correcto
    while (*stack_b != NULL) {
        pa(stack_a, stack_b); // Mueve el elemento superior de `stack_b` a `stack_a`
        // Puede ser necesario usar una estrategia similar a `smart_move` aquí para decidir cuándo rotar `stack_a`
    }
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

// condigo de kurval

static int	calc_size(t_stack *root)
{
	t_stack *current;
	int		size;

	size = 0;
	current = root;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int			shortest_way(t_stack *root, int value)
{
	int		size;
	int		moves;
	int		pos;
	t_stack *current;
	int		mid;

	pos = 0;
	moves = 0;
	size = calc_size(root);
	mid = size / 2;
	current = root;
	while (current->value != value)
	{
		current = current->next;
		pos++;
	}
	if (pos <= mid)
		moves += pos;
	else
		moves = (-1 * (size - pos));
	return (moves);
}

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_list(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j += 1;
		}
		i += 1;
	}
}

int			*sort_tab(t_stack *root_a, int size)
{
	t_stack *current;
	int		*tab;
	int		i;

	current = root_a;
	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * size + 1)))
		return (0);
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	sort_list(tab, size);
	return (tab);
}

static void	move_b(t_stack **root_a, t_stack **root_b, int *tab, int *size)
{
	int way;

	way = shortest_way(*root_b, tab[*size]);
	while ((*root_b)->value != tab[*size])
	{
		if ((*root_b)->next)
		{
			if ((*root_b)->next->value == tab[*size])
			{
				sa(root_b);
				break ;
			}
		}
		if (way < 0)
			rra(root_b);
		else
			ra(root_b);
	}
	*size -= 1;
	pa(root_b, root_a);
}

static void	move_partitions(t_stack **root_a, t_stack **root_b,\
		int pivot, int pos)
{
	int round;

	round = (*root_a)->value;
	pos = pivot - pos;
	ra(root_a);
	while ((*root_a)->value != round && pos > 0)
	{
		if ((*root_a)->value <= pivot)
		{
			pa(root_a, root_b);
			pos--;
		}
		else
			ra(root_a);
	}
	if ((*root_a)->value <= pivot)
		pa(root_a, root_b);
}

void		big_sort(t_stack **root_a, t_stack **root_b, int size)
{
	int mid;
	int	*tab;
	int len;
	int round;
	int pos;

	mid = 0;
	pos = 0;
	tab = sort_tab(*root_a, size);
	len = size - 1;
	round = (size <= 100) ? 2 : 1;
	while (!is_empty(*root_a) && round <= 10)
	{
		mid = (round == 10) ? tab[len] : tab[(size / 10) * round];
		move_partitions(root_a, root_b, mid, pos);
		pos = mid;
		round = (size <= 100) ? round + 2 : round + 1;
	}
	while (!is_empty(*root_b))
		move_b(root_a, root_b, tab, &len);
	free(tab);
}

void push_swap_sort(t_stack **stack_a, t_stack **stack_b, int total_numbers, int num_chunks)
{
    int chunk_size = total_numbers / num_chunks;
    int remaining_numbers = total_numbers;
    (void) stack_b;
    for (int i = 0; i < num_chunks; ++i) {
        int chunk_start = i * chunk_size;
        int chunk_end = chunk_start + chunk_size - 1;
        
        // Ajusta el último chunk para incluir todos los números restantes
        if (i == num_chunks - 1) {
            chunk_end += remaining_numbers - chunk_size;
        }

        int hold_first = find_hold_first(*stack_a, chunk_start, chunk_end);
        int hold_second = find_hold_second(*stack_a, chunk_start, chunk_end);
        printf("first: %d", hold_first);
        printf("second: %d", hold_second);
        // Decidir cuál de los dos mover a stack_b y moverlo
        // Este esquema no incluye la lógica específica para decidir y mover,
        // pero necesitarás implementar la lógica para elegir entre hold_first y hold_second
        // basado en la cantidad de movimientos necesarios y luego realizar el movimiento.
        
        remaining_numbers -= chunk_size;
    }

    // Tras procesar todos los chunks, el siguiente paso sería reordenar los números desde stack_b a stack_a.
}