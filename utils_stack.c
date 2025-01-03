/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:38 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/03 18:53:29 by icunha-t         ###   ########.fr       */
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

t_stack_node	*find_highest_node(t_stack_node *stack)
{
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest_node = stack;
	while (stack)
	{
		if (stack->value > highest_node->value)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
}

t_stack_node	*find_lowest_node(t_stack_node *stack)
{
	t_stack_node	*lowest_node;

	if (!stack)
		return (NULL);
	lowest_node = stack;
	while (stack)
	{
		if (stack->value < lowest_node->value)
			lowest_node = stack;
		stack = stack->next;
	}
	return (lowest_node);
}

t_stack_node	*find_second_lowest_node(t_stack_node *stack)
{
	t_stack_node	*second_lowest_node;
	t_stack_node	*lowest_node;

	if (!stack)
		return (NULL);
	second_lowest_node = stack;
	lowest_node = find_lowest_node(stack);
	while (stack)
	{
		if (stack != lowest_node)
		{
			second_lowest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	while (stack)
	{
		if (stack != lowest_node && stack->value < second_lowest_node->value)
			second_lowest_node = stack;
		stack = stack->next;
	}
	return (second_lowest_node);
}

int	ft_stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
