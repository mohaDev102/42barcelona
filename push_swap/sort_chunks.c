
#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dest)
{
	if (*src == NULL)
		return ;
	t_stack *temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	ft_insert_int_to_top(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		// Manejar el error si no se puede asignar memoria
		exit(1);
	}
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

// void	ft_do_pb(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		value;
// 	t_stack	*temp;

// 	if (*stack_a == NULL)
// 	{
// 		// No se puede hacer push si el stack A está vacío
// 		return ;
// 	}
// 	// Tomar el valor del primer elemento del stack A
// 	value = (*stack_a)->value;
// 	// Insertar el valor en la parte superior del stack B
// 	ft_insert_int_to_top(stack_b, value);
// 	// Eliminar el primer elemento del stack A
// 	temp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	free(temp);
// }
void	ft_do_pb(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;
	// if (stack_a == NULL || (*stack_a)->size == 0)
	//     return ;
	// stack_b->size += 1;
	// (*stack_a)->size -= 1;
    printf("null: %d", (*stack_a)->size);
    write(1, "w", 1);
	temp = (*stack_a)->stack[0];
	ft_memmove((*stack_b)->stack + 1, (*stack_b)->stack, (*stack_b)->size * sizeof(int));
	ft_memmove((*stack_a)->stack, (*stack_a)->stack + 1, (*stack_a)->size * sizeof(int));
	(*stack_b)->stack[0] = temp;
    // printf("%d", stack_a->stack[0]);
    // ft_print_instruction("pb");
}

void	ft_do_rotate(t_stack *stack)
{
	int	first;
    write(1, "si", 2);
    if (stack->size == 0)
        return ;
    first = stack->stack[0];
    ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
    stack->stack[stack->size - 1] = first;
    write(1, "no", 2);
}


int	ft_get_min_int_index(t_stack *stack, int min_int)
{
	for (int i = 0; i < stack->size; i++)
	{
		if (stack->stack[i] == min_int)
		{
			return (i);
		}
	}
	return (-1); // En caso de no encontrar el valor
}

int	ft_find_next_min_int(t_stack *stack, int current_min)
{
	int	next_min;

	next_min = INT_MAX;
	for (int i = 0; i < stack->size; i++)
	{
		if (stack->stack[i] > current_min && stack->stack[i] < next_min)
		{
			next_min = stack->stack[i];
		}
	}
	return (next_min);
}

int	ft_find_min_int(t_stack *stack)
{
	int	min_int;

	min_int = INT_MAX;
	for (int i = 0; i < stack->size; i++)
	{
		if (stack->stack[i] < min_int)
		{
			min_int = stack->stack[i];
		}
	}
	return (min_int);
}

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
			ft_insert_int_to_top(&stack_a, stack_a->stack[index]);
			ft_do_pb(&stack_a, &stack_b);
            printf("%d", stack_b->stack[0]);
			if (stack_b->stack[0] < stack_a->middle)
            {
                write(1, "ent\n", 4);
				ft_do_rotate(stack_b);
            }
            write(1, "ew\n", 3);
		}
	}
	// ft_push_b_to_a(stack_a, stack_b);
	ft_push(&stack_b, &stack_a);
}

