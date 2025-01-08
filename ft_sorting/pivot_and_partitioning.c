/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_and_partitioning.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/08 17:13:40 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_find_pivot(t_stack_node **a)
{
	t_stack_node	*highest_node;
	t_stack_node	*lowest_node;
	int				pivot;

	highest_node = find_highest_node(*a);
	lowest_node = find_lowest_node(*a);
	pivot = (highest_node->value + lowest_node->value) / 2;
	return (pivot);
}

void	partition_element(t_stack_node **a, t_stack_node **b, int pivot)
{
	if ((*a)->value <= pivot)
		pb(b, a, true);
	else
		ra(a, true);
}

void	ft_part_stack(t_stack_node **a, t_stack_node **b)
{
	int	pivot;
	int	size;
	int	i;

	pivot = ft_find_pivot(a);
	size = ft_stack_len(*a);
	i = 0;
	if (ft_stack_len(*a) <= 3)
		return ;
	while (i < size)
	{
		partition_element(a, b, pivot);
		i++;
	}
	(*b)->chunk_end = true;
	ft_part_stack(a, b);
}
/*

//MORE THAN 25 LINES

static int	ft_find_pivot(t_stack_node **a)
{
	t_stack_node	*highest_node;
	t_stack_node	*lowest_node;
	int	pivot;
	
	highest_node = find_highest_node(*a);
	ft_printf("highest value is %d\n", highest_node->value);
	lowest_node = find_lowest_node(*a);
	ft_printf("lowest value is %d\n", lowest_node->value);
	pivot = (highest_node->value + lowest_node->value) / 2;
	ft_printf("pivot is %d\n", pivot);
	return (pivot);
}

void	ft_part_stack(t_stack_node **a, t_stack_node **b)
{
	int				pivot;
	int				size;
	int				i;
	t_stack_node	*current;

	pivot = ft_find_pivot(a);
	size = ft_stack_len(*a);
	i = 0;
	current = *a;
	if (ft_stack_len(*a) <= 3)
		return ;
	while (i++ < size)
	{
		if (current->value <= pivot)
		{
			while ((*a)->value != current->value)
				ra(a, true);
			pb(b, a, true);
		}
		else
			ra(a, true);
		current = *a;
	}
	(*b)->chunk_end = true;
	ft_printf("Partitioned ");
	print_stack(*a, "A");
	ft_printf("Partitioned ");
	print_stack(*b, "B");
	ft_part_stack(a, b);
}
*/
