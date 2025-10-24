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
    struct s_list *node;
}               t_list;

long int ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	error(void);
void	is_valid(char *str);
int		ft_is_number(char c);
void		ft_is_overflow(long int number);
#endif