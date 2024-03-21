
#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        // int i;
        // int num;
        t_stack *stack_a = NULL;

        
        // i = 1;
        if (check_number(argv, argc))
        {
            write(1, "error\n", 6);
            exit(1);
        }
        
        push_stack(&stack_a, argv);
        // while (i < argc)
        // {
        //     num = ft_atoi(argv[i]);
        //     // push_stack(&stack_a, num);
        //     // if (!new_node)
        //     //     exit(1);
        //     // new_node->next = stack_a;
        //     // stack_a = new_node;
        //     // is_sorted(num);
        //     //check_number(num);
        //     // push_stack(num1);
        //     i++;
        // }
        // printf("first: %d\n", get_first_value(stack_a));
        // printf("last: %d\n", get_last_value(stack_a));
        if (is_sorted(&stack_a))
        {
            // write(1, "ordenada", 8);
            free(stack_a);
            exit(0);
        }
        else
            sort_stack(&stack_a);
        print_stack(&stack_a);
        return (0);

    }
}