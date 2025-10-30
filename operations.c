/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayonal <ayonal@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:27:13 by ayonal            #+#    #+#             */
/*   Updated: 2025/10/30 15:27:13 by ayonal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	t_list	*temp;
	int		temp_val;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->next;
	temp_val = (*stack)->value;
	(*stack)->value = temp->value;
	temp->value = temp_val;
	write(1, "sa\n", 3);
}

void	ra(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	first = *stack;
	*stack = (*stack)->next;
	while (first->next)
		first = first->next;
	first->next = last;
	last->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list **stack)
{
	t_list	*first;
	t_list	*last_second;

	if (!*stack || !(*stack)->next)
		return ;
	last_second = *stack;
	first = *stack;
	while (last_second->next->next != NULL)
		last_second = last_second->next;
	*stack = last_second->next;
	(*stack)->next = first;
	last_second->next = NULL;
	write(1, "rra\n", 4);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}
