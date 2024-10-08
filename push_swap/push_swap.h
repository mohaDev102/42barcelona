
# ifndef PUSH_SWAP
#define PUSH_SWAP
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int index;
    int value;
    struct s_stack *next;
} t_stack;

int ft_atoi(char *str);
size_t ft_strlen(const char *c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strcpy(char *s1, char *s2);
int check_number(char **str, int argc);
int is_sorted(t_stack **stack_a);
void    push_stack(t_stack **stack, char **str);
void print_stack(t_stack *stack);
int is_duplicated(int num, t_stack *value_stack);
t_stack	*ft_lstnew(int value);
void sort_stack(t_stack **stack_a, t_stack **stack_b);
int ft_lstsize(t_stack **stack);
void sa(t_stack **stack_a);
void sort_three(t_stack **stack);
void rra(t_stack **stack_a);
void	ft_lstaddend(t_stack **alst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void ra(t_stack **stack_a);
void sort_chunks(t_stack **a, t_stack **b, int chunk_size);
void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, int chunk_size);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void	*ft_memmove(void *dst, const void *src, size_t len);
void init_stack(t_stack **stack_a);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void	assign_index(t_stack **stack, int *sorted_values, int size);
void assign_indices(t_stack **stack);
void sort_stack_100(t_stack **stack_a, t_stack **stack_b);
int find_position_of_first_min(t_stack *stack);
int find_position_by_index(t_stack *stack, int index);
void smart_move(t_stack **stack);
void smart_move_b(t_stack **stack_b);
void		big_sort(t_stack **root_a, t_stack **root_b, int size);
void push_swap_sort(t_stack **stack_a, t_stack **stack_b, int total_numbers, int num_chunks);
void sort_big(t_stack **stack_a, t_stack **stack_b);
void free_stacks(t_stack *stack_a, t_stack *stack_b);
#endif