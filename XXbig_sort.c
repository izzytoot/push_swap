/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:19:07 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/28 18:40:54 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_alg(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a > 3 && !ft_is_stack_sorted(*a))
		pb(b, a, false);
	if (len_a > 3 && !ft_is_stack_sorted(*a))
		pb(b, a, false);
	while (len_a > 3 && !ft_is_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_mini_sort(a);
}
