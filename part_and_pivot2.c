/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_and_pivot2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:00 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/02 18:30:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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

static void	ft_pos_pivot(t_stack_node *a, int pivot)
{
	t_stack_node	*current;

	current = a;
	while (a)
	{
		if (a->value == pivot)
		{
			ft_swap (current, current->next);
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
				pivot_node = current;
				ft_printf("pivot node is %d\n", pivot_node->value);
			}
			current = current->next;
			if (current->value > pivot)
				ft_swap(current, last);
		}
		while (current !=last && last->value > pivot)
			last = last->prev;
		if (current != last && current->prev != last)
		{
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


static void	ft_swap(t_stack_node *node1, t_stack_node *node2)
{
	int	temp;

	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}



static void	ft_swap(t_stack_node *node1, t_stack_node *node2)
{
	int	temp;

	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}
void	ft_part_stack(t_stack_node **a)
{
	t_stack_node	*pivot_node;
	t_stack_node	*current;
	t_stack_node	*prev;
//	t_stack_node	*last;
	t_stack_node	*next_node;
	if (!a || !*a || !(*a)->next)
		return ;
	pivot_node = *a; // pivot is 1st element of stack
//	last = find_last_node(*a);
	current = (*a)->next; // we start with current at the 2nd element
	prev = *a; // so previous is 1st element (in this case the pivot)
	ft_printf("pivot is %d\n", pivot_node->value);
	/*
	if (pivot_node == find_highest_node(*a))
	{	
		ft_swap(pivot_node, last);
		return ;
	}
	// runs all elements of stack, since NULL is the last element
	while (current->next != NULL)
	{
		next_node = current->next;
		prev = current->prev;
		if (current->value < pivot_node->value)
		{
			ft_printf("1");
			// we will move element to left of pivot, so next of previous will be next of current
			// (2 elements to the right)
			prev->next = current->next;
			// current will move to left of *a (meaning that a* is next of current)
			current->next->prev = prev;
			current->next = *a;
			// meaning that current will become the 1st element of stack (*a)
			*a = current;
			current = next_node;
			ft_printf("2");
		}
		else
			current = next_node;
		ft_printf("3 ");

		ft_printf("\nnew version: \n");
		print_stack(*a, "A");
	}
	if (current->value < pivot_node->value)
	{
			prev->next = NULL;
			current->next = *a;
			*a = current;
	}
}
*/