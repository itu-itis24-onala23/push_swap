/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayonal <ayonal@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:12:59 by ayonal            #+#    #+#             */
/*   Updated: 2025/10/30 15:13:01 by ayonal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_overflow(long int number)
{
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	return (1);
}

int	is_valid(char *str)
{
	int	i;
	int	control;

	i = 0;
	control = 1;
	if (str[i] == '\0')
		control = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		control = 0;
	while (str[i] != '\0')
	{
		if (!(ft_is_number(str[i])))
		{
			control = 0;
			break ;
		}
		i++;
	}
	return (control);
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

int	is_duplicate(t_list *stack)
{
	t_list	*first;
	t_list	*second;

	first = stack;
	while (first != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (first->value == second->value)
			{
				free_stack(stack);
				return (0);
			}
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}
