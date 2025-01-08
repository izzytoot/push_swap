/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:36 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/08 10:46:48 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_mini_sort_3(t_stack_node **stack)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*stack);
	if (!(*stack)->next)
		return ;
	if (*stack == highest_node)
		ra(stack, true);
	else if ((*stack)->next == highest_node)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	ft_mini_sort_5(t_stack_node **stack_1, t_stack_node **stack_2)
{
	t_stack_node	*lowest_node;
	t_stack_node	*second_lowest_node;
	int				i;

	lowest_node = find_lowest_node(*stack_1);
	second_lowest_node = find_second_lowest_node (*stack_1);
	i = 0;
	while (*stack_1 != lowest_node)
	{
		ra(stack_1, true);
		i++;
	}
	pb(stack_2, stack_1, true);
	while (*stack_1 != second_lowest_node)
	{
		if (i > 2)
			rra(stack_1, true);
		else
			ra(stack_1, true);
	}
	pb(stack_2, stack_1, true);
	ft_mini_sort_3(stack_1);
	pa(stack_1, stack_2, true);
	pa(stack_1, stack_2, true);
}
