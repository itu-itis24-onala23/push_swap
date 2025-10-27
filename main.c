#include "push_swap.h"
static void part1(t_list *stack, char **str)
{
	if (!str || str[0] == NULL)
	{
	free_stack(stack);
	free_func(str);
	error();
	}
}
static void	part2(char **str, int j, t_list **stack)
{
	long int number;

	while (str[j] != NULL)
	{
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
static void part3(t_list **stack, t_list **stack_b)
{
	int size;

	size = count_nodes(*stack);
	if(size == 2)
		two_sort(*stack);
	else if(size == 3)
		three_sort(stack);
	else if(size >= 4 && size <= 10)
		four_to_ten(stack, stack_b);
	else
		big_number(stack, stack_b, size);
}

int	main(int argc, char **argv)
{
	int i;
	char **str;
	t_list *stack;
	t_list *stack_b; 

	i = 1;
	stack = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		part1(stack,str);
		part2(str, 0, &stack);
		free_func(str);
		i++;
	}
	print_stack(stack);
	part3(&stack, &stack_b);
	print_stack(stack);
	free_stack(stack);
}
