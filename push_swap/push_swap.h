
# ifndef PUSH_SWAP
#define PUSH_SWAP
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
int is_sorted(t_stack *stack_a);
void    push_stack(t_stack **stack, int num);
void print_stack(t_stack *stack);
#endif