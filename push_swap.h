#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int            value;
    struct s_list *node;
}               t_list;

int ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);
#endif