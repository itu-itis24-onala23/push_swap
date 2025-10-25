#include "push_swap.h"

void	free_func(char **str)
{
	int j;

	j = 0;
	if (!str)
		return ;
	while (str[j] != NULL)
		free(str[j++]);
	free(str);
}
void	part1(char **str, int j, t_list **stack)
{
	long int number;

	while (str[j] != NULL)
	{
		printf("splitten ayrilan %s", str[j]);
		if (!(is_valid(str[j])))
		{
			free_stack(*stack);
			free_func(str);
			error();
		}
		number = ft_atoi(str[j]);
		if (!(ft_is_overflow(number)))
		{
			free_stack(*stack);
			free_func(str);
			error();
		}
		push_stack_end(stack, number);
		if(!(is_duplicate(*stack)))
		{
			free_func(str);
			error();
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	char **str;
	t_list *stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str || str[0] == NULL)
		{
			free_stack(stack);
			free_func(str);
			error();
		}
		part1(str, 0, &stack);
		free_func(str);
		i++;
	}
	print_stack(stack);
	free_stack(stack);
}
