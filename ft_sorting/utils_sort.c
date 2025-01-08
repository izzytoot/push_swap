/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:38 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/08 17:45:25 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	if (!stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*ft_find_cheapest_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	ft_prep_for_push(t_stack_node **stack_1, t_stack_node **stack_2, char name_stack1)
{
	t_stack_node	*top_wanted_stack1;
	t_stack_node	*top_wanted_stack2;

	top_wanted_stack2 = ft_find_cheapest_node(*stack_2);
	top_wanted_stack1 = top_wanted_stack2->target_node;
	
	while(*stack_1 != top_wanted_stack1)
	{
		if (name_stack1 == 'a')
		{
			if (top_wanted_stack1->above_median_len)
				ra(stack_1, true);
			else
				rra(stack_1, true);
		}
		else
		{
			if (top_wanted_stack1->above_median_len)
				rb(stack_1, true);
			else
				rrb(stack_1, true);
		}
		
	}
}
