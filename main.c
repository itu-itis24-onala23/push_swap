#include "push_swap.h"


int	main(int argc, char **argv)
{
	int i;
	int j;
	long int number;
	char **str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL)
			return (1);
		j = 0;
		while (str[j] != NULL)
		{
			is_valid(str[j]);
			number = ft_atoi(str[j]);
			ft_is_overflow(number);
			j++;
		}
		j = 0;
		while (str[j] != NULL)
			free(str[j++]);
		free(str);
		i++;
	}
}
