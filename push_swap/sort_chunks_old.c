
#include "push_swap.h"

// <<<<<<< HEAD
// void ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
// =======
void ft_push(t_stack **src, t_stack **dest)
{
    if (*src == NULL)
        return;
    t_stack *temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

void ft_insert_int_to_top(t_stack **stack, int value)
{
    t_stack *new_node;

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
void ft_do_pb(t_stack **stack_a, t_stack **stack_b)
{
    int temp;
    t_stack *curr;
    t_stack *curr1;

    curr = *stack_a;
    curr1 = *stack_b;
    if (curr == NULL || curr->size == 0)
        return ;
    curr1->size += 1;
    curr->size -= 1;
    // printf("ss: %d", curr->size);
    write(1, "s", 1);
    temp = curr->stack[0];
    ft_memmove(curr1->stack + 1, curr1->stack, curr1->size * sizeof(int));
    ft_memmove(curr->stack, curr->stack + 1, curr->size * sizeof(int));
    curr1->stack[0] = temp;
    // printf("%d", stack_a->stack[0]);
    // ft_print_instruction("pb");
}

void ft_do_rotate(t_stack *stack)
{
    int first;
    write(1, "si", 2);
    if (stack->size == 0)
        return;
    first = stack->stack[0];
    ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
    stack->stack[stack->size - 1] = first;
    write(1, "no", 2);
}

int ft_get_min_int_index(t_stack *stack, int min_int)
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

int ft_find_next_min_int(t_stack *stack, int current_min)
{
    int next_min;

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

int ft_find_min_int(t_stack *stack)
{
    int min_int;

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

void ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
    int index;
    int min_int;
    int times;

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
            if (stack_b->stack[0] < stack_a->middle)
                ft_do_rotate(stack_b);
        }
    }
    ft_push(&stack_a, &stack_b);
}

int init_stack(t_stack **stack_a)
{
    t_stack *curr;

    curr = *stack_a;
    if (curr == NULL)
    {
        curr = (t_stack *)malloc(sizeof(t_stack));
        if (curr == NULL)
        {
            // Manejar el error si no se puede asignar memoria
            exit(1);
        }
    }
    curr->size = 0;
        // printf("ss%d", (*stack_a)->size);
        // write(1, "s", 1);
        curr->middle = 0;
        curr->next = NULL; // Asegurar que el puntero 'next' esté inicializado correctamente
    return (1);
}

// void ft_do_rotate(t_stack *stack)
// {
//     if (stack->size > 0)
//     {
//         int first = stack->stack[0];
//         for (int i = 0; i < stack->size - 1; i++)
//         {
//             stack->stack[i] = stack->stack[i + 1];
//         }
//         stack->stack[stack->size - 1] = first;
//     }
// }

// int ft_get_min_int_index(t_stack *stack, int min_int)
// {
//     for (int i = 0; i < stack->size; i++)
//     {
//         if (stack->stack[i] == min_int)
//         {
//             return i;
//         }
//     }
//     return -1; // En caso de no encontrar el valor
// }

// int ft_find_next_min_int(t_stack *stack, int current_min)
// {
//     int next_min = INT_MAX;
//     for (int i = 0; i < stack->size; i++)
//     {
//         if (stack->stack[i] > current_min && stack->stack[i] < next_min)
//         {
//             next_min = stack->stack[i];
//         }
//     }
//     return next_min;
// }

// int ft_find_min_int(t_stack *stack)
// {
//     int min_int = INT_MAX;
//     for (int i = 0; i < stack->size; i++)
//     {
//         if (stack->stack[i] < min_int)
//         {
//             min_int = stack->stack[i];
//         }
//     }
//     return min_int;
// }

// void ft_rotate(t_stack **stack)
// {
//     if (*stack == NULL || (*stack)->next == NULL)
//         return;

//     t_stack *first = *stack;
//     t_stack *current = *stack;

//     while (current->next != NULL)
//     {
//         current = current->next;
//     }

//     *stack = first->next;  // El segundo nodo ahora es el primero
//     first->next = NULL;    // El antiguo primer nodo ahora es el último
//     current->next = first; // Enlazar el antiguo primer nodo al final
// }

// void ft_push(t_stack **src, t_stack **dest)
// {
//     if (*src == NULL)
//         return;
//     t_stack *temp = *src;
//     *src = (*src)->next;
//     temp->next = *dest;
//     *dest = temp;
// }
// =======
// >>>>>>> 635bd754ab373549fe9d4047bca0a35e2ed06eef
