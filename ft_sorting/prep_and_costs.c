/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_and_costs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:13:39 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/08 17:22:22 by icunha-t         ###   ########.fr       */
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

void	ft_set_cheapest(t_stack_node *stack)
{
	int				cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_prep_for_comeback(t_stack_node *a, t_stack_node *b)
{
	ft_current_position(a);
	ft_current_position(b);
	ft_find_target_for_b(a, b);
	ft_calc_moves(a, b);
	ft_set_cheapest(b);
}

/*
//COMMENTED VERSION
void	ft_current_position(t_stack_node *stack)
{
	int	i;
	int	median_len;
	
	if(!stack)
		return ;
	i = 0;
	median_len = ft_stack_len(stack) / 2;
//	ft_printf("stack len is %d\n", ft_stack_len(stack));
//	ft_printf("median is %d\n", median_len);
	while(stack)
	{
		stack->position = i;
		if (i <= median_len)
			stack->above_median_len = true;
		else
			stack->above_median_len = false;
		if (stack->above_median_len)
			ft_printf("%d is position %d and is above median.\n", stack->value, stack->position);
		if (!stack->above_median_len)
			ft_printf("%d is position %d and is below median.\n", stack->value, stack->position);
		stack = stack->next;
		i++;
	}
}

void	ft_find_target_for_b(t_stack_node *stack_1, t_stack_node *stack_2)
{
	t_stack_node	*current_stack_1;
	t_stack_node	*target_node;
	int				closest_bigger;

	while(stack_2)
	{
		closest_bigger = INT_MAX;
		current_stack_1 = stack_1;
		while (current_stack_1)
		{
			if(current_stack_1->value > stack_2->value && current_stack_1->value < closest_bigger)
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
		ft_printf("TN for %d is %d\n", stack_2->value, target_node->value);
		stack_2 = stack_2->next;
	}
}

void	ft_calculate_moves(t_stack_node *stack_1, t_stack_node *stack_2)
{
	int	len_stack_1;
	int	len_stack_2;

	len_stack_1 = ft_stack_len(stack_1);
	len_stack_2 = ft_stack_len(stack_2);
	while(stack_2)
	{
		stack_2->cost = stack_2->position;
		if (!stack_2->above_median_len)
			stack_2->cost = len_stack_2 - (stack_2->position);
		if (stack_2->target_node->above_median_len)
			stack_2->cost = stack_2->cost + stack_2->target_node->position;
		else
			stack_2->cost = stack_2 ->cost + (len_stack_1) - (stack_2->target_node->position);
		ft_printf("cost of %d is %d\n", stack_2->value, stack_2->cost);
		stack_2 = stack_2->next;
	}
}

void	ft_find_cheapest(t_stack_node *stack)
{
	int	cheapest_value;
	t_stack_node	*cheapest_node;
	
	if(!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
	ft_printf("cheapest node is %d\n", cheapest_node->value);
}

void	ft_prep_nodes_b(t_stack_node *a, t_stack_node *b)
{
	ft_current_position(a);
	ft_current_position(b);
	ft_find_target_for_b(a, b);
	ft_calculate_moves(a, b);
	ft_find_cheapest(b);
}
*/