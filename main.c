/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:36 by root              #+#    #+#             */
/*   Updated: 2025/01/03 14:54:19 by icunha-t         ###   ########.fr       */
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
	int	top_value;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = split(av[1], ' ');
	ft_stack_init(&a, av + (ac != 2));
	top_value = a->value;
	ft_printf("Initial ");
	print_stack(a, "A");
	ft_printf("Initial ");
	print_stack(b, "B");
	ra(&a, false);
	ft_printf("rotated ");
	print_stack(a, "A");
	rra(&a, false);
	ft_printf("reverse rotated ");
	print_stack(a, "A");
	sa(&a, false);
	ft_printf("swaped ");
	print_stack(a, "A");
	while(a)
	{
		pb(&b, &a, false);
	}
	ft_printf("pushed from a to b ");
	print_stack(b, "B");
	rb(&b, false);
	ft_printf("rotated ");
	print_stack(b, "B");
	rrb(&b, false);
	ft_printf("reverse rotated ");
	print_stack(b, "B");
	sb(&b, false);
	ft_printf("swaped ");
	print_stack(b, "B");
	while(b)
	{
		pa(&a, &b, false);
	}
	ft_printf("pushed from b to a ");
	print_stack(a, "A");
	pb(&b, &a, false);
	pb(&b, &a, false);
	ft_printf("new ");
	print_stack(a, "A");
	ft_printf("new ");
	print_stack(b, "B");
	rr (&a, &b, false);
	ft_printf("double rev ");
	print_stack(a, "A");
	print_stack(b, "B");
	rrr (&a, &b, false);
	ft_printf("double rr ");
	print_stack(a, "A");
	print_stack(b, "B");
	ss (&a, &b, false);
	ft_printf("double swap ");
	print_stack(a, "A");
	print_stack(b, "B");
	return (0);
}
