/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:42:21 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/20 13:07:47 by icunha-t         ###   ########.fr       */
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

float	find_pivot(t_stack_node *a)
{
	int	*buffer;
	int	i;
	int	size;
	int	j;
	float	median;
	
	size = ft_stack_len(a);
	buffer = ft_stack_cpy(a, size);
	i = 0;
	while(i++ < size - 1)
	{
		j = 0;
		while(j++ < size - i - 1)
		{
			if(buffer[j] > buffer[j + 1])
				ft_swap(&buffer[j], &buffer[j + 1]);
		}
	}
	if (size % 2 == 0)
		median = (buffer[size/2 - 1] + buffer[size / 2]) / 2;
	else
		median = buffer[size / 2];
	free(buffer);
	return(median);	
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
/*
int	main (void)
{
	t_stack_node	*a;
	t_stack_node	node1 = {1, NULL, NULL};
	t_stack_node	node2 = {7, &node1, NULL};
	t_stack_node	node3 = {8, &node2, NULL};
	t_stack_node	node4 = {10, &node3, NULL};
	t_stack_node	node5 = {-5, &node4, NULL};
	node1.prev = &node2;
	node2.prev = &node3;
	node3.prev = &node4;
	node4.prev = &node5;
	a = &node5;
	float median = find_pivot(a);
	print_stack(a, "A");
	ft_printf("median is: %f\n", median);
}
*/

int	main (void)
{
	t_stack_node	*a;
	t_stack_node	node1 = {1, NULL, NULL};
	t_stack_node	node2 = {7, &node1, NULL};
	t_stack_node	node3 = {8, &node2, NULL};
	t_stack_node	node4 = {10, &node3, NULL};
	t_stack_node	node5 = {-5, &node4, NULL};
	node1.prev = &node2;
	node2.prev = &node3;
	node3.prev = &node4;
	node4.prev = &node5;
	a = &node5;
	
	int	size = ft_stack_len(a);
	ft_printf("Stack size: %d\n", size);
	int	*buffer;
	buffer = malloc(sizeof(int) * size);
	if (!buffer) 
	{
		ft_printf("Failed to malloc stack in main \n");
        return 1;
	}
	buffer = ft_stack_cpy(a, size);
	if (!buffer) 
	{
		ft_printf("Failed to copy stack\n");
        return 1;
	}
	int	i = 0;
	while (i < size)
	{
		ft_printf("%d ", buffer[i]);
		i++;
	}
	free(buffer);
	return(0);
}
