/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:36 by root              #+#    #+#             */
/*   Updated: 2025/01/10 11:31:42 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_av;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		split_av = split(av[1], ' ');
		av = split_av;
		ft_stack_init(&a, av);
		free_split(split_av);
	}
	else
		ft_stack_init(&a, av + 1);
	if (!ft_is_stack_sorted(a))
		ft_sorting_alg(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
