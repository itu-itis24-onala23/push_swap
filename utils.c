#include "push_swap.h"
void free_stack(t_list *stack)
{
	t_list *temp;
	while(stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
void	error(void)
{
	write(2, "error\n", 7);
	exit(1); //hata ile çıkış
}
int count_nodes(t_list *stack)
{
	int i;

	i = 0;
	while(stack != NULL)
	{
		i++;
		stack = stack->next; 
	}
	return (i);
}
int find_index(t_list *stack)
{
	int index;
	int i;
	int min;

	i = 0;
	index = 0;
	min = stack->value;
	while(stack != NULL)
	{
		if(min > stack->value)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}