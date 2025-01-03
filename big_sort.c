/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:19:07 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/03 15:42:03 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_alg(t_stack_node **a, t_stack_node **b)
{
	if (ft_stack_len(*a) <= 3)
		{
			ft_mini_sort(a);
			return ;
		}
	else
	{
		ft_part_stack(a);
		ft_printf("Partitioned ");
		print_stack(*a, "A");
		while (ft_stack_len(*a) > 3)
			pb(b, a, false);
		ft_printf("Left of ");
		print_stack(*a, "A");
		ft_mini_sort(a);
		ft_printf("New ");
		print_stack(*b, "B");
	}
}
