/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:19:07 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/06 14:56:25 by icunha-t         ###   ########.fr       */
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
	int	i;
	
	i = 0;
	ft_part_stack(a, b);
	if (!ft_is_stack_sorted(*a))
		ft_mini_sort_3(a);
//	while (ft_stack_len(*b) > 3)
//	{
	ft_mini_sort_5(b, a);
/*
		while(i <= 5)
		{
			pa(a, b, true);
			i++;
		}
		ft_printf("after push ");
		print_stack(*a, "A");
		ft_printf("after push - ");
		print_stack(*b, "B");
		i = 0;
	}
	if(ft_stack_len(*b) > 0)
	{
		if(ft_is_stack_sorted(*b))
			ft_mini_sort_3(b);
		while(ft_stack_len(*b) > 0)
			pa(a, b, true);	
	}
*/
}

