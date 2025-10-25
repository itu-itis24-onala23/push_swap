#include "push_swap.h"
t_list	*new_node(int value)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->value = value;
	a->next = NULL;
	return (a);
}
void push_stack(t_list  **stack, int value)
{
	t_list *new_node;
	
	new_node->next = *stack;
	*stack = new_node;

}