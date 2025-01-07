/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:38 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/07 15:51:41 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	if (!stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_abs(int	n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}