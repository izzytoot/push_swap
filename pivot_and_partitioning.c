/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_and_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/31 16:54:11 by root             ###   ########.fr       */
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

void	ft_part_stack(t_stack_node *a)
{
	int	pivot;
	t_stack_node	*current;
	t_stack_node	*last;
	t_stack_node	*pivot_node;	
	if (!a || !(a)->next)
		return ;
	pivot = ft_find_pivot(a);
	current = a;
	last = find_last_node(a);
	pivot_node = NULL;
	while (current && last && current != last && current->prev != last)
	{
		while (current != last && current->value <= pivot)
		{
			if(current->value == pivot)
			{	
				ft_printf("0\n");
				pivot_node = current;
				ft_printf("pivot node is %d\n", pivot_node->value);
			}
			current = current->next;
			if (current->value > pivot)
				ft_swap(current, last);
		}
		while (current !=last && last->value > pivot)
		{
			ft_printf("1\n");
			last = last->prev;
		}
		if (current != last && current->prev != last)
		{
			ft_printf("2\n");
			ft_swap(current, last);
			ft_printf("swapped %d with %d\n", current->value, last->value);
			current = current->next;
			last = last->prev;
		}
	}
	if (pivot_node && pivot_node->value < last->value)
	{
		ft_printf("swapped pivot %d with %d\n", pivot_node->value, last->value);
		ft_swap(pivot_node, last);
	}
}
