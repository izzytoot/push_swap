/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:31 by root              #+#    #+#             */
/*   Updated: 2024/12/27 16:44:01 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//ARGUMENT INITIAL SORTING OUT
char			**split(char *str, char c);
void			ft_stack_init(t_stack_node **a, char **av);
void			ft_append_node(t_stack_node **stack, int n);

//ERRORS
int				ft_error_handling(char *str);

//FREEING
void			ft_free_errors(t_stack_node **a);
void			ft_free_stack(t_stack_node **stack);

//SORTING
void			ft_mini_sort(t_stack_node	**a);
void			ft_sorting_alg(t_stack_node **a, t_stack_node **b);

//COMMANDS
void			sa(t_stack_node **a, bool check);
void			sb(t_stack_node **b, bool check);
void			ss(t_stack_node **a, t_stack_node **b, bool check);
void			pa(t_stack_node **a, t_stack_node **b, bool check);
void			pb(t_stack_node **b, t_stack_node **a, bool check);
void			ra(t_stack_node **a, bool check);
void			rb(t_stack_node **b, bool check);
void			rr(t_stack_node **a, t_stack_node **b, bool check);
void			rra(t_stack_node **a, bool check);
void			rrb(t_stack_node **b, bool check);
void			rrr(t_stack_node **a, t_stack_node **b, bool check);

//LIST UTILS
t_stack_node	*find_last_node(t_stack_node *stack);
bool			ft_is_stack_sorted(t_stack_node *stack);
t_stack_node	*find_highest_node(t_stack_node *stack);
int				ft_stack_len(t_stack_node *stack);
int				*ft_stack_cpy(t_stack_node *stack, int size);

#endif
