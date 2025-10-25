#include "push_swap.h"

void free_func(char **str)
{
	int j;

	j = 0;
	while(str[j] != NULL)
		free(str[j++]);
	free(str);
}
int	main(int argc, char **argv)
{
	int i;
	int j;
	int control;
	long int number;
	char **str;

	i = 1;
	control = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str[0] == NULL || !str)
		{
			free_func(str);
			error();
		}
		j = 0;
		while (str[j] != NULL)
		{
			printf("splitten ayrilan %s",str[j]);
			control = is_valid(str[j]);
			if(control)
			{
				number = ft_atoi(str[j]);
				control = ft_is_overflow(number);
			}
			if(control == 0)
			{
				free_func(str);
				error();
			}
			j++;
		}
		free_func(str);
		i++;
	}
}
