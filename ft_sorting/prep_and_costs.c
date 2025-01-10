/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_and_costs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:13:39 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:42 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_current_position(t_stack_node *stack)
{
	int	i;
	int	median_len;

	if (!stack)
		return ;
	i = 0;
	median_len = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median_len)
			stack->above_median_len = true;
		else
			stack->above_median_len = false;
		stack = stack->next;
		i++;
	}
}

void	ft_find_target_for_b(t_stack_node *stack_1, t_stack_node *stack_2)
{
	t_stack_node	*current_stack_1;
	t_stack_node	*target_node;
	int				closest_bigger;

	while (stack_2)
	{
		closest_bigger = INT_MAX;
		current_stack_1 = stack_1;
		while (current_stack_1)
		{
			if (current_stack_1->value > stack_2->value
				&& current_stack_1->value < closest_bigger)
			{
				closest_bigger = current_stack_1->value;
				target_node = current_stack_1;
			}
			current_stack_1 = current_stack_1->next;
		}
		if (closest_bigger == INT_MAX)
			stack_2->target_node = find_lowest_node(stack_1);
		else
			stack_2->target_node = target_node;
		stack_2 = stack_2->next;
	}
}

void	ft_calc_moves(t_stack_node *stack_1, t_stack_node *stack_2)
{
	int	len_stack_1;
	int	len_stack_2;

	len_stack_1 = ft_stack_len(stack_1);
	len_stack_2 = ft_stack_len(stack_2);
	while (stack_2)
	{
		stack_2->cost = stack_2->position;
		if (!stack_2->above_median_len)
			stack_2->cost = len_stack_2 - (stack_2->position);
		if (stack_2->target_node->above_median_len)
			stack_2->cost += stack_2->target_node->position;
		else
			stack_2->cost += (len_stack_1) - (stack_2->target_node->position);
		stack_2 = stack_2->next;
	}
}

void	ft_prep_for_push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_wanted_a;
	t_stack_node	*top_wanted_b;

	top_wanted_b = ft_find_cheapest_node(*b);
	top_wanted_a = top_wanted_b->target_node;
	while (*a != top_wanted_a)
	{
		if (top_wanted_a->above_median_len)
			ra(a, true);
		else
			rra(a, true);
	}
	while (*b != top_wanted_b)
	{
		if (top_wanted_b->above_median_len)
			rb(b, true);
		else
			rrb(b, true);
	}
}

void	ft_prep_for_comeback(t_stack_node *a, t_stack_node *b)
{
	ft_current_position(a);
	ft_current_position(b);
	ft_find_target_for_b(a, b);
	ft_calc_moves(a, b);
	ft_set_cheapest(b);
}
