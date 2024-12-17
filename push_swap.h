/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:31 by root              #+#    #+#             */
/*   Updated: 2024/12/17 17:06:19 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int	value;
	int	index;
	int	cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
}	t_stack_node;

//ARGUMENT INITIAL SORTING OUT
char	**split(char *str, char c);
void	ft_stack_init(t_stack_node **a, char **av);
void	ft_append_node(t_stack_node **stack, int n);

//ERRORS
int	ft_error_handling(char *str);
long ft_atol(const char *str);

//FREEING
void	ft_free_errors(t_stack_node **a);
void ft_free_stack(t_stack_node **stack);

//LIST UTILS
t_stack_node	*find_last_node(t_stack_node *stack);


//COMMANDS
//ft_swap (sa, sb, ss)
//ft_rotate (ra, rb, rr)
//ft_rrotate (rra, rrb, rrr)
//ft_push (pa, pb)
//sa(&a, false);

//stack_len(a)
//ft_check errors
//stack sorted
//stack len
//sa
//mini sort
//sort stacks 



#endif
