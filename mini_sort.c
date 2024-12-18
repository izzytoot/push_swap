/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:40:36 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 15:03:44 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_sort(t_stack_node	**a)
{
	t_stack_node	*highest_nbr;

	highest_nbr = find_highest_node(*a);
	if (*a == highest_nbr)
		ra(a, false);
	else if ((*a)->next == highest_nbr)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
