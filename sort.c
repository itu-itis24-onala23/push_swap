#include "push_swap.h"

void two_sort(t_list **stack)
{
    if((*stack)->value > (*stack)->next->value)
        sa(stack);
}
void three_sort(t_list **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->value;
    b = (*stack) ->next->value;
    c = (*stack)->next->next->value;
    if(a > b && b < c && a < c)
        sa(stack);
    else if(a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if(a > b && b < c && a > c)
        ra(stack);
    else if(a < b && a < c && c < b)
    {
        sa(stack);
        ra(stack);
    }
    else if(a < b && b > c && a > c)
        rra(stack);
}
void four_to_ten(t_list **stacka, t_list **stackb,int size)
{
    int min_index;
    int step;

     while(size > 3)
    {
        min_index = find_index(*stacka);
        if(min_index < size / 2)
        {
            step = min_index;
            while(step-- > 0)
                ra(stacka);
        }
        else
        {
            step = size - min_index;
            while(step-- > 0)
                rra(stacka);
        }
        pb(stacka, stackb);
        size--;
    }
        three_sort(stacka);
        while(*stackb != NULL)
            pa(stacka, stackb);
}

