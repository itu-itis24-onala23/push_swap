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
}               t_list;

long int ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	error(void);
int	is_valid(char *str);
int		ft_is_number(char c);
int		ft_is_overflow(long int number);
void        free_func(char **str);
void	part1(char **str, int j, t_list **stack);
void free_stack(t_list *stack);
int is_duplicate(t_list *stack);
void	push_stack_end(t_list **stack, int value);
void print_stack(t_list *stack);
void two_sort(t_list *stack);
void sa(t_list *stack);
int count_nodes(t_list *stack);
int find_index(t_list *stack);

#endif