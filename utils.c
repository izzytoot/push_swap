/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:38 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 16:07:02 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	ft_is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	find_highest_node(t_stack_node *stack)
{
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest_node = stack;
	while (stack)
	{
		if (stack->value > highest_node->value)
			highest_node = stack;
		highest_node = stack->next;
	}
	return (highest_node);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if(!stack)
		return (0);
	while (stack)
	{
		stack = stack->next
		count++;
	}
	return (count);
}