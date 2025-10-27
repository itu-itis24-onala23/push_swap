#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int            value;
    struct s_list  *next;
    int             index;
}               t_list;

long int ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	error(void);
int     is_valid(char *str);
int		ft_is_number(char c);
int		ft_is_overflow(long int number);
void    free_func(char **str);
void    free_stack(t_list *stack);
int     is_duplicate(t_list *stack);
void	push_stack_end(t_list **stack, int value);
void    print_stack(t_list *stack);

int count_nodes(t_list *stack);
int find_index(t_list *stack);

void big_number(t_list **a, t_list **b, int size);
void two_sort(t_list *stack);
void three_sort(t_list **stack);
void four_to_ten(t_list **stacka, t_list **stackb);


void sa(t_list *stack);
void ra(t_list **stack);
void rra(t_list **stack);
void pb(t_list **a, t_list **b);
void pa(t_list **a, t_list **b);
#endif