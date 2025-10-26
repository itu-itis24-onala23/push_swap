#include "push_swap.h"

void sa(t_list *stack)
{
    t_list *temp;
    int temp_val;

    if(!stack || !stack->next)
        return;
    temp = stack->next;
    temp_val = stack->value;
    stack->value = temp->value;
    temp->value= temp_val;
    write(1,"sa\n",4);
}
//stackin en tepesindeki elemanı alıp en alta taşır
void ra(t_list **stack)
{
    t_list *last;
    t_list *first;

    if(!*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    last = *stack;

    while(last->next != NULL)
        last = last->next;
    last->next = first;
    write(1,"ra\n",4);
}
//stackin en altındaki elemanı alıp tepeye taşır
void rra(t_list **stack)
{
    t_list *first;
    t_list *last_second;

    if(!*stack || !(*stack)->next)
        return;
    last_second = *stack;
    first = *stack;
    while(last_second->next->next != NULL)
        last_second = last_second ->next;
    *stack = last_second->next;
    (*stack)->next = first;
    last_second->next = NULL;
    write(1,"rra\n",4);
}
void pb(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *a;
    (*a) = (*a)->next;
    temp->next = *b;
    *b = temp;
    write(1,"pb\n",3);
}
void pa(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write(1,"pa\n",3);
}