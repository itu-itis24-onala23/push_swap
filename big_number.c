#include "push_swap.h"

static void set_index(t_list **stack_a)
{
    t_list *temp;
    t_list *first;
    int     index;

    first = *stack_a;
    while(first)
    {
        index = 0;
        temp = *stack_a;
        while(temp)
        {
            if(temp->value < first->value)
                index++;
            temp = temp->next;
        }
        first->index = index;
        first = first->next;
    }
}

static int find_bit(int number)
{
    int i;

    i = 0;
    if(number == 0)
        return (1);
    while(number >> i != 0)
        i++;
    return (i);
}
void big_number(t_list **a, t_list **b, int size)
{
    int max_bits;
    int i;
    int j;
    int current_size;

    set_index(a);
    int max_index = size - 1;
    max_bits = find_bit(max_index);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        current_size = count_nodes(*a);
        while (j < current_size)
        {
            if ((((*a)->index >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}

