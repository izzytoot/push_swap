/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:13:39 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/07 17:39:10 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_cheapest(t_stack_node **a, t_stack_node **b, int start, int current_len)
{
	int		end;
	int		cheapest;
	int		lowest_nb_moves;
	int		moves;
	
	end = start + current_len;
	lowest_nb_moves = INT_MAX;
	cheapest = -1;
	while (start <= end)
	{
		moves = ft_calculate_moves(a, b, *ft_which_item(*b, start));
		if (moves < lowest_nb_moves)
		{
			lowest_nb_moves = moves;
			cheapest = *ft_which_item(*b, start);
		}
		start++;
	}
	return(cheapest);
}

int	ft_calculate_moves(t_stack_node **a, t_stack_node **b, int	current)
{
	int	moves_a;
	int	moves_b;

	moves_a = ft_find_distance(a, ft_find_next(a, current));
	moves_b = ft_find_distance(b, current);
	if((moves_a <= 0 && moves_b >= 0) || (moves_a >= 0 && moves_b <=0))
		return (ft_abs(moves_a - moves_b));
	if(ft_abs(moves_a) > ft_abs(moves_b))
		return (ft_abs(moves_a));
	return(ft_abs(moves_b));
}

int	ft_find_distance(t_stack_node **stack, int	nbr)
{
	int	i;

	if(nbr < 0)
		return (0);
	i = -1;
	while (ft_which_item(*stack, i))
	{
		if(*ft_which_item(*stack, i) == nbr)	
			break ;
		++i;
	}
	if (i > (ft_stack_len(*stack) / 2))
		return (-1 * (ft_stack_len(*stack) - i));
	return (i);
}

int	ft_find_next(t_stack_node **stack, int nbr)
{
	int	next;
	int	current;
	int	i;

	if (ft_stack_len(*stack) < 1)
		return (-1);
	next = INT_MAX;
	i = -1;
	while (ft_which_item(*stack, i))
	{
		current = *ft_which_item(*stack, i);
		if (current > nbr && current < next)
			next = current;
		++i;
	}
	if (next == INT_MAX)
		return (ft_find_next(stack, -1));
	return (next);
}


int	*ft_which_item(t_stack_node *stack, int i)
{
	int	head_position;
	int	tail_position;
	
	if(i >= 0 && i < ft_stack_len(stack))
	{
		head_position = i % ft_stack_len(stack);
		return (&stack->value);
	}
	else if (i < 0 && i >= ft_stack_len(stack))
	{
		tail_position = (-1 + i + (ft_stack_len(stack) + 1) % ft_stack_len(stack));
		return (&stack->value);
	}
	return (NULL);
}

void	ft_find_best_insert(t_stack_node **a, t_stack_node **b)
{
	int		cheapest;
	int		current_len;
	int		current_round;
	int		start;

	current_round = -1;
	while (b)
	{
		current_len = ft_stack_len(*b) / 4;
		if (current_len > ft_stack_len(*b))
			current_len = ft_stack_len(*b);
		start = (++current_round % 2) * -current_len;
		while (current_len)
		{
			cheapest = ft_find_cheapest(a, b, start, current_len);
			ft_printf("best insert is %d", cheapest);
			start = start - ft_find_distance(b, cheapest);
			if (start < -current_len || start + current_len >= ft_stack_len(*b))
				start = -current_len;
			while ((*a)->value != ft_find_next(a, cheapest))
				ra(a, true);
			while ((*b)->value != cheapest)
				rb(b, true);
			pa(a, b, true);
		}
		*b = (*b)->next;
	}
}