/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:28:39 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/09 14:00:53 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack_node **stack_1, t_stack_node **stack_2)
{
	t_stack_node	*pushed_nbr;

	if (!stack_2 || !*stack_2)
		return ;
	pushed_nbr = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_2)
		(*stack_2)->prev = NULL;
	pushed_nbr->prev = NULL;
	if (!*stack_1)
	{
		*stack_1 = pushed_nbr;
		pushed_nbr->next = NULL;
	}
	else
	{
		pushed_nbr->next = *stack_1;
		pushed_nbr->next->prev = pushed_nbr;
		*stack_1 = pushed_nbr;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print_check)
{
	push(a, b);
	if (print_check)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print_check)
{
	push(b, a);
	if (print_check)
		ft_printf("pb\n");
}
