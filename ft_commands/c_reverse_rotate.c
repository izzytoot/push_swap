/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:44 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/09 14:03:21 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print_check)
{
	reverse_rotate(a);
	if (print_check)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print_check)
{
	reverse_rotate(b);
	if (print_check)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print_check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_check)
		ft_printf("rrr\n");
}
