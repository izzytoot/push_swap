/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:42:21 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/28 18:59:23 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
	ft_stack_init(&a, av + (ac != 2));
	print_stack(a, "A");
	int pivot = find_pivot(a);
	ft_printf("pivot is: %d\n", pivot);
	ft_printf("new Stack A:\n");
	part_buffer(a);
	ft_free_stack(&a);
	return (0);
}
*/