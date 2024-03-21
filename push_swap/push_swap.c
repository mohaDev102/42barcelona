
#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        t_stack *stack_a = NULL;
        if (check_number(argv, argc))
        {
            write(1, "error\n", 6);
            exit(1);
        }
        push_stack(&stack_a, argv);
        if (is_sorted(&stack_a))
        {
            // write(1, "ordenada", 8);
            free(stack_a);
            exit(0);
        }
        else
            sort_stack(&stack_a);
        print_stack(stack_a);
        return (0);
    }
}