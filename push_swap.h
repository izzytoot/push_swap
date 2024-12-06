/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:31 by root              #+#    #+#             */
/*   Updated: 2024/12/06 15:18:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int	value;
	int	current_position;
	int	final_index;
	int	push_price;
//??	bool	above_median;
//??	bool	cheapest;
//??	struct s_stack_node	*target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

main functions:
ft_initiate stack 

commands:
ft_swap (sa, sb, ss)
ft_rotate (ra, rb, rr)
ft_rrotate (rra, rrb, rrr)
ft_push (pa, pb)

utils:
ft_split
ft_atol 
ft_check errors
ft_free_errors
ft_find_last_node


#endif
