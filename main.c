/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:36 by root              #+#    #+#             */
/*   Updated: 2025/01/06 11:54:17 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
	if (!ft_is_stack_sorted(a))
		ft_sorting_alg(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
*/

//COMMENTED VERSION
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
	ft_printf("Initial ");
	print_stack(b, "B");
	if (!ft_is_stack_sorted(a))
		ft_sorting_alg(&a, &b);
	else
		ft_printf("Stack already sorted");
	ft_printf("Final ");
	print_stack(a, "A");
	ft_printf("Final ");
	print_stack(b, "B");
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
