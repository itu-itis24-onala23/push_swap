#include "push_swap.h"
void	push_stack_end(t_list **stack, int value)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		error();
	new_node->value = value;
	new_node->next = NULL;

	if (!*stack) // stack boşsa, direkt buradan başlat
	{
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}
void print_stack(t_list *stack)
{
    t_list *tmp = stack;

    printf("Stack: ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->value); // node değerini yaz
        tmp = tmp->next;           // bir sonraki node’a geç
    }
    printf("\n");
}

