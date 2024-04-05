
#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        t_stack *stack_a = NULL;
        t_stack *stack_b = NULL;
        if (check_number(argv, argc))
        {
            write(1, "error\n", 6);
            exit(1);
        }
        push_stack(&stack_a, argv);
        // init_stack(&stack_a);
        if (is_sorted(&stack_a))
        {
            free_stacks(stack_a, stack_b);
            exit(0);
        }
        else
            sort_stack(&stack_a, &stack_b);
        // print_stack(stack_a);
        free_stacks(stack_a, stack_b);
        // printf("stack_b\n");
        // print_stack(stack_b);
        return (0);
    }
}