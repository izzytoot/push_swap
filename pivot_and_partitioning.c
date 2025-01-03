/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_and_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/03 13:42:30 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_to_beginning(t_stack_node **a, t_stack_node **prev_node,
		t_stack_node **current, t_stack_node **next_node)
{
	(*prev_node)->next = (*current)->next;
	(*current)->next->prev = *prev_node;
	(*current)->next = *a;
	*a = *current;
	*current = *next_node;
}

void	ft_part_stack(t_stack_node **a)
{
	t_stack_node	*pivot_node;
	t_stack_node	*current;
	t_stack_node	*prev_node;
	t_stack_node	*next_node;

	if (!a || !*a || !(*a)->next)
		return ;
	pivot_node = *a;
	current = (*a)->next;
	while (current->next)
	{
		next_node = current->next;
		prev_node = current->prev;
		if (current->value < pivot_node->value)
			ft_move_to_beginning(a, &prev_node, &current, &next_node);
		else
			current = next_node;
	}
	prev_node = current->prev;
	if (current->value < pivot_node->value)
	{
		prev_node->next = NULL;
		current->next = *a;
		*a = current;
	}
}
