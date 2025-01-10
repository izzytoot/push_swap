/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:22:23 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/09 14:02:05 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack_node **new_head)
{
	if (!*new_head || !(*new_head)->next)
		return ;
	*new_head = (*new_head)->next;
	(*new_head)->prev->prev = *new_head;
	(*new_head)->prev->next = (*new_head)->next;
	if ((*new_head)->next)
		(*new_head)->next->prev = (*new_head)->prev;
	(*new_head)->next = (*new_head)->prev;
	(*new_head)->prev = NULL;
}

void	sa(t_stack_node **a, bool print_check)
{
	swap(a);
	if (print_check)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print_check)
{
	swap(b);
	if (print_check)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print_check)
{
	swap(a);
	swap(b);
	if (print_check)
		ft_printf("ss\n");
}
