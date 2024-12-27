/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:42:21 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:45 by icunha-t         ###   ########.fr       */
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

int	find_pivot(t_stack_node *a)
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

void	part_buffer(int pivot, t_stack_node *a)
{
	int	*buffer;
	int	size;
	int	first;
	int	last;
	
	size = ft_stack_len(a);
	buffer = ft_stack_cpy(a, size);
	if (!buffer)
		return ;
	first = 0;
	last = size - 1;
	while (first < last) 
	{
        while (buffer[first] < pivot && first < last)
            first++;
        while (buffer[last] >= pivot && first < last)
            last--;
        if (first < last)
            ft_swap(&buffer[first], &buffer[last]);
    }
	if (pivot != buffer[last])
		ft_swap(&buffer[last], &buffer[size - 1]);
	free(buffer);
}

void	print_stack(t_stack_node *stack, char *name)
{
	ft_printf("Stack %s:\n", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = split(av[1], ' ');
	ft_stack_init(&a, av + (ac == 2 ? 0 : 1));
	print_stack(a, "A");
	int pivot = find_pivot(a);
	ft_printf("pivot is: %d\n", pivot);
	part_buffer(pivot, a);
	ft_free_stack(&a);
	return (0);
}
