/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:36 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/05 14:42:04 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_sort_3(t_stack_node **stack)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*stack);
	if (*stack == highest_node)
		ra(stack, true);
	else if ((*stack)->next == highest_node)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	ft_mini_sort_5(t_stack_node **stack_one, t_stack_node **stack_two)
{
	t_stack_node	*lowest_node;
	t_stack_node	*second_lowest_node;
	int				i;

	lowest_node = find_lowest_node(*stack_one);
	second_lowest_node = find_second_lowest_node (*stack_one);
	i = 0;
	while (*stack_one != lowest_node)
	{
		ra(stack_one, true);
		i++;
	}
	pb(stack_two, stack_one, true);
	while (*stack_one != second_lowest_node)
	{
		if (i > 2)
			rra(stack_one, true);
		else
			ra(stack_one, true);
	}
	pb(stack_two, stack_one, true);
	ft_mini_sort_3(stack_one);
	pa(stack_one, stack_two, true);
	pa(stack_one, stack_two, true);
}
