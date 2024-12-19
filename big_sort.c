/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:19:07 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/19 18:23:42 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	b = temp;
}

void	find_pivot(t_stack_node *a)
{
	int	*buffer;
	int	i;
	int	size;
	int	j;
	float	median;
	
	size = ft_stack_len(a);
	buffer = ft_stack_cpy(buffer, a, size);
	i = 0;
	while(i++ < size - 1)
	{
		j = 0;
		while(j++ < size - i - 1)
		{
			if(buffer[j] > buffer[j + 1])
				ft_swap(buffer[j], buffer[j + 1]);
		}
	}
	if (size % 2 == 0)
		median = (buffer[size/2 - 1] + buffer[size / 2]) / 2;
	else
		median = buffer[size / 2];
	free(buffer);
	return(median);	
}


void	ft_sorting_alg(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a > 3 && !ft_is_stack_sorted(*a))
		pb(b, a, false);
	if (len_a > 3 && !ft_is_stack_sorted(*a))
		pb(b, a, false);
	while (len_a > 3 && !ft_is_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	ft_mini_sort(a);
}
