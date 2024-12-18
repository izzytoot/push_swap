/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:47:35 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 16:12:59 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	
	if(!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	
}

void	ra(t_stack_node **a, bool check)
{
	rotate(a);
	if(!check)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool check)
{
	rotate(b);
	if(!check)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool check)
{
	rotate(a);
	rotate(b);
	if(!check)
		ft_printf("rr\n");
}