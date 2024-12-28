/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_and_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/28 21:47:04 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack_node *node1, t_stack_node *node2)
{
	int	temp;

	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}

int	ft_find_pivot(t_stack_node *a)
{
	int	pivot;
	int	first;
	int	mid;
	int	last;

	if (!a || !a->next || !a->next->next)
		return a->value;
	first = a->value;
	mid = a->next->value;
	last = a->next->next->value;
	if ((first > mid) != (first > last))
		pivot = first;
	else if ((mid > first) != (mid > last))
		pivot = mid;
	else
		pivot = last;
	return (pivot);
}

static void	ft_pos_pivot(t_stack_node *a, int pivot)
{
	t_stack_node	*current;

	current = a;
	while (a)
	{
		if (a->value == pivot)
		{
			ft_swap (&current, &current->next);
			break ;
		}
		a = a->next;
	}
}

void	ft_part_stack(t_stack_node *a)
{
	int	pivot;
	t_stack_node	*current;
	t_stack_node	*last;
	
	pivot = ft_find_pivot(a);
	current = a;
	last = find_last_node(a);
	if (!a || !(a)->next)
		return ;
	while (current != last && current->prev != last)
	{
		while (current != last && current->value < pivot)
			current = current->next;
		while (current !=last && last->value >= pivot)
			last = last->prev;
		if (current != last)
		{
			ft_swap(current, last);
			current = current->next;
			last = last->prev;
		}
	}
}


