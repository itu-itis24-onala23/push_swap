#include "push_swap.h"

// sadece + veya- den (bir tane olacak )veya sayılardan oluşmalı herhangi bir başka şey icermemeli
// + ve - sadece başta olacak yani sayı ortasında "4-2" olamaz
int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
void ft_is_overflow(long int number)
{
	if(number > INT_MAX || number < INT_MIN)
		error();
}
void	is_valid(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		error();
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		error();
	while (str[i] != '\0')
	{
		if (!(ft_is_number(str[i])))
		{
			printf("%c ",str[i]);	
			error();
		}
		i++;
	}
}
long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}