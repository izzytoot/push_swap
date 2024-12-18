/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:55:22 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 13:41:35 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_handling(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-')
		&& (!(str[i++] >= '0' && str[i++] <= '9')))
		return (1);
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node->next;
		node->value = 0;
		free(node);
		node = temp;
	}
	*stack = NULL;
}

void	ft_free_errors(t_stack_node **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
