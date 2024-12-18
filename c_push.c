/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:28:39 by icunha-t          #+#    #+#             */
/*   Updated: 2024/12/18 15:46:04 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node *pushed_nbr;
	
	if(!src)
		return ;
	pushed_nbr = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	pushed_nbr->prev = NULL;
	if(!*dest)
	{
		*dest = pushed_nbr;
		pushed_nbr->next = NULL;
	}
	else{
		pushed_nbr->next = *dest;
		pushed_nbr->next->prev = *pushed_nbr;
		*dest = pushed_nbr;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if(!check)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool check)
{
	push(b, a);
	if(!check)
		ft_printf("pb\n");
}