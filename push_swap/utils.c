
#include "push_swap.h"

int ft_atoi(char *str)
{
    int sign;
    int res;
    int i;

    i = 0;
    sign = 1;
    res = 0;
    if (str[i] == '-')
    {
        sign *= -1;
    }
    while (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}

int check_number(char **str, int argc)
{
    int i = 0;
    int j = 1;
    while (j < argc)
    {
        i = 0;
        if (str[j][i] == '\0')
            return (1);
        if (str[j][i] == '-')
            i++;
        while (str[j][i] != '\0')
        {
            if ((str[j][i] < '0' || str[j][i] > '9') && str[j][i] != '-')
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}

int is_sorted(t_stack **stack_a)
{
    t_stack *curr;

    curr = *stack_a;
    if (curr == NULL || curr->next == NULL)
        return 1;
    while (curr->next != NULL)
    {
        if (curr->value > curr->next->value)
            return (0);
        curr = curr->next;
    }
    return (1);
}

t_stack	*ft_lstnew(int value)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
    new->next = NULL;
	return (new);
}

void push_stack(t_stack **stack_a, char **str)
{
    int i;
    int num;
    i = 1;
    t_stack *curr;
    t_stack *root;

    curr = NULL;
    root = *stack_a;
    while (str[i] != NULL)
    {
        num = ft_atoi(str[i]);
        if (is_duplicated(num, root))
        {
            // si pongo el mensaje de error cuando
            // es un numero tambien lo hace y creo
            // lo tendria que ignorar
            // write(1, "error\n", 6);
            exit(1);
        }
        if (!root)
        {
            root = ft_lstnew(num);
            curr = root;
        }
        else
        {
            curr->next = ft_lstnew(num);
            curr = curr->next;
        }
        i++;
    }
    *stack_a = root;   
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("valor: %d\t index:%d\n", stack->value, stack->index);
        stack = stack->next;
    }
}

void ft_free(t_stack *stack)
{
     t_stack *current;
    t_stack *next;

    if (stack == NULL) {
        return ;
    }

    current = stack;
    while (current != NULL) 
    {
        next = current->next; // Guarda el siguiente nodo
        free(current); // Libera el nodo actual
        current = next; // Mueve al siguiente nodo
    }

    stack = NULL; 
}

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    ft_free(stack_a);
    ft_free(stack_b);
}

int is_duplicated(int  num, t_stack *value_stack)
{
        while (value_stack != NULL)
        {
            if (num == value_stack->value)
                return (1);
            value_stack = value_stack->next;
        }
    return (0);
}
