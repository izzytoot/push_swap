/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:36 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/03 18:55:54 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_sort_3(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	ft_mini_sort_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lowest_node;
	t_stack_node	*second_lowest_node;
	int				i;

	lowest_node = find_lowest_node(*a);
	second_lowest_node = find_second_lowest_node (*a);
	i = 0;
	while (*a != lowest_node)
	{
		ra(a, false);
		i++;
	}
	pb(b, a, false);
	while (*a != second_lowest_node)
	{
		if (i > 2)
			rra(a, false);
		else
			ra(a, false);
	}
	pb(b, a, false);
	ft_mini_sort_3(a);
	pa(a, b, false);
	pa(a, b, false);
}
