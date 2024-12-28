/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_and_pivot2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/28 21:27:45 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_find_pivot(t_stack_node *a)
{
	int	*buffer;
	int	size;
	int	pivot;
	int	first;
	int	mid;
	int	last;

	size = ft_stack_len(a);
	buffer = ft_stack_cpy(a, size);
	if (!buffer)
		return (0);
	first = buffer[0];
	mid = buffer[size / 2];
	last = buffer[size - 1];
	if ((first > mid) != (first > last))
		pivot = first;
	else if ((mid > first) != (mid > last))
		pivot = mid;
	else
		pivot = last;
	free (buffer);
	return (pivot);
}

static void	ft_pos_pivot(int *buffer, int pivot, int size, int first)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == pivot)
		{
			ft_swap (&buffer[first], &buffer[i]);
			break ;
		}
		i++;
	}
}

void	ft_part_buffer(t_stack_node *a)
{
	int	*buffer;
	int	size;
	int	first;
	int	last;
	int	pivot;

	size = ft_stack_len(a);
	buffer = ft_stack_cpy(a, size);
	pivot = ft_find_pivot(a);
	if (!buffer)
		return ;
	first = 0;
	last = size - 1;
	while (first <= last)
	{
		while (buffer[first] < pivot)
			first++;
		while (buffer[last] >= pivot)
			last--;
		if (first < last)
			ft_swap(&buffer[first], &buffer[last]);
	}
	ft_pos_pivot(buffer, pivot, size, first);
	free(buffer);
}



void	ft_part_stack(t_stack_node *a)
{
	int	pivot;
	t_stack_node	*first;
	t_stack_node	*last;
	
	pivot = ft_find_pivot(a);
	first = a;
	last = NULL;
	if (!a || !(a)->next)
		return ;
	while (first)
	{
		if (first->value < pivot)
		{
			if(last != NULL)
				ft_swap(&last->value, &first->value);
			last = first;
		}
		first = first->next;
	}
	if (last && last->next)
			ft_swap(&last->value, &first->value);
}