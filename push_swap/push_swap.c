
#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        int i;
        int num;
        t_stack *stack_a = NULL;

        // stack_a;
        i = 1;
        if (check_number(argv, argc))
        {
            write(1, "error\n", 6);
            exit(1);
        }
        while (i < argc)
        {
            num = ft_atoi(argv[i]);
            push_stack(&stack_a, num);
            // is_sorted(num);
            //check_number(num);
            // push_stack(num1);
            i++;
        }
        // print_stack(stack_a);
        if (is_sorted(stack_a))
        {
            write(1, "ordenada", 8);
            exit(0);
        }
        else
            write(1, "no ordenada", 11);
        return (0);

    }
}