/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:19:07 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/09 19:38:57 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sorting_alg(t_stack_node **a, t_stack_node **b)
{
	if (ft_stack_len(*a) == 2)
	{
		sa(a, true);
		return ;
	}
	if (ft_stack_len(*a) == 3)
	{
		ft_mini_sort_3(a);
		return ;
	}
	if (ft_stack_len(*a) == 5)
	{
		ft_mini_sort_5(a, b);
		return ;
	}
	else
		ft_big_sort(a, b);
}

void	ft_big_sort(t_stack_node **a, t_stack_node **b)
{
	ft_part_stack(a, b);
	if (!ft_is_stack_sorted(*a))
		ft_sorting_alg(a, b);
	while (*b)
	{
		(*b)->chunk_end = false;
		while (*b && !(*b)->chunk_end)
		{
			ft_prep_for_comeback(*a, *b);
			ft_prep_for_push(a, b);
			pa(a, b, true);
		}
	}
	ft_lowest_on_top(a);
}
