
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
        while (str[j][i] != '\0')
        {
            if (str[j][i] < '0' || str[j][i] > '9')
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}

int is_sorted(t_stack *stack_a)
{
    if (stack_a == NULL || stack_a->next == NULL)
        return 1;
    while (stack_a->next != NULL)
    {
        if (stack_a->value > stack_a->next->value)
        {
            printf("%d", stack_a->value);
            return (0);
        }
        stack_a = stack_a->next;
    }
    return (1);
}

void push_stack(t_stack **stack_a, int num)
{
    // t_stack *stack_a;
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
        return ;
    new_node->value = num;
    new_node->next = *stack_a;
    // printf("%d", new_node->value);
    *stack_a = new_node;
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}
