
#include "push_swap.h"

int ft_atoi(char *str)
{
    int sign;
    int res;
    int i;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '-')
        sign *= -1;
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
        {
            printf("%d", curr->value);
            return (0);
        }
        curr = curr->next;
    }
    return (1);
}

t_stack	*ft_lstnew(int value)
{
	t_stack *prueba;

	prueba = (t_stack *)malloc(sizeof(t_stack));
	if (!prueba)
		return (NULL);
	prueba->value = value;
    prueba->next = NULL;
	return (prueba);
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

    
    // t_stack *curr;

    // root = *stack_a;
    // // new_node = ft_lstnew(num);
    // curr = NULL;
    // if (!root)
    // {
    //     root = ft_lstnew(num);
    //     curr = root;
    // }
    // else
    // {
    //     // curr = root;
    //     curr->next = ft_lstnew(num);
    //     // printf("%d", new_node->next->value);
    //     curr = curr->next;
    // }
    // if (!first)
    // {
    //     first = ft_lstnew(num);
    //     first->value = num;
    //     first->next = curr;
    // }
    // else
    // {
    //     curr->value = num;
    //     curr->next = ft_lstnew(num); 
    // }
    // *stack_a = first;
}

void print_stack(t_stack **stack)
{
    t_stack *curr;
    curr = *stack;
    while (curr != NULL)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
}

int get_first_value(t_stack *stack) 
{
    if (stack == NULL) {
        printf("La lista está vacía.\n");
        return -1; // Valor de retorno de error, puedes ajustarlo según sea necesario
    }
    return stack->value;
}


int get_last_value(t_stack *stack)
{
    if (stack == NULL) {
        printf("La lista está vacía.\n");
        return -1; // Valor de retorno de error, puedes ajustarlo según sea necesario
    }
    while (stack->next != NULL) {
        stack = stack->next;
    }
    return stack->value;
}