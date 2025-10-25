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