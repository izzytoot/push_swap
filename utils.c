/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:38 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/20 13:06:55 by icunha-t         ###   ########.fr       */
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

t_stack_node	*find_highest_node(t_stack_node *stack)
{
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest_node = stack;
	while (stack->next)
	{
		if (stack->value > highest_node->value)
			highest_node = stack;
		stack = stack->next;
	}
	return (highest_node);
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

int	*ft_stack_cpy(t_stack_node *stack, int size)
{
	t_stack_node *current;
	int	*buffer;
	int	i;
	if (!stack || size <= 0)
		return (NULL);
	buffer = malloc(sizeof(int) * size);
	if(!buffer)
	{
		ft_printf("failed step malloc");
		return (NULL);
	}
	current = stack;
	i = 0;
	while(i < size)
	{
		if (!current) 
		{
			free(buffer);
            return (NULL);
		}
		ft_printf("Copying value: %d at index %d\n", current->value, i);
		buffer[i] = current->value;
		current = current->next;
		i++;
	}
	return (buffer);
}
