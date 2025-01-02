/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:36 by root              #+#    #+#             */
/*   Updated: 2025/01/02 18:33:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("Initial ");
	print_stack(a, "A");
	ft_part_stack(&a);
	ft_printf("Changed ");
	print_stack(a, "A");
	return (0);
}
/*
if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			mini_sort(&a);
		else
			ft_sorting_alg(&a, &b);
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
	ft_stack_init(&a, av + (ac != 2));
	print_stack(a, "A");
	int pivot = ft_find_pivot(a);
	ft_printf("pivot is: %d\n", pivot);
	ft_printf("new Stack A:\n");
	ft_part_buffer(a, buffer, pivot);
	ft_free_stack(&a);
	return (0);
}
*/