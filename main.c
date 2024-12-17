/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:36 by root              #+#    #+#             */
/*   Updated: 2024/12/17 16:32:40 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == NULL))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	stack_init(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2);
			sa(&a, false);
		else if(stack_len(a) == 3)
			mini_sort(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
