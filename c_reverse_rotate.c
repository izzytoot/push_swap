/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:44 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 16:17:25 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	
	if(!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->next = last_node;
}

void	rra(t_stack_node **a, bool check)
{
	reverse_rotate(a);
	if(!check)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool check)
{
	reverse_rotate(b);
	if(!check)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if(!check)
		ft_printf("rrr\n");
}