/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:31 by root              #+#    #+#             */
/*   Updated: 2025/01/13 13:53:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include "libft/libft.h"

/* ************************************************************************** */
/*                                    STRUCTS                                 */
/* ************************************************************************** */
typedef struct s_stack_node
{
	int					value;
	int					cost;
	int					position;
	bool				above_median_len;
	bool				cheapest;
	bool				chunk_end;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* ************************************************************************** */
/*                                  FUNCTIONS                                 */
/* ************************************************************************** */

/********************************* FT_COMMANDS ********************************/

// c_push.c
void			pa(t_stack_node **a, t_stack_node **b, bool print_check);
void			pb(t_stack_node **b, t_stack_node **a, bool print_check);
// c_reverse_rotate.c
void			rra(t_stack_node **a, bool print_check);
void			rrb(t_stack_node **b, bool print_check);
void			rrr(t_stack_node **a, t_stack_node **b, bool print_check);
// c_rotate.c
void			ra(t_stack_node **a, bool print_check);
void			rb(t_stack_node **b, bool print_check);
void			rr(t_stack_node **a, t_stack_node **b, bool print_check);
// c_swap.c
void			sa(t_stack_node **a, bool print_check);
void			sb(t_stack_node **b, bool print_check);
void			ss(t_stack_node **a, t_stack_node **b, bool print_check);

/********************************** FT_INIT *********************************/

// error_handling.c
int				ft_error_char(char *str);
int				ft_error_repeat(t_stack_node *stack, int n);
void			ft_free_errors(t_stack_node **stack, char **array, int ac);
void			ft_free_stack(t_stack_node **stack);

// stack_init.c
void			ft_stack_init(t_stack_node **a, char **av, int ac);
void			ft_append_node(t_stack_node **stack, int n);
void			ft_free_split(char **array);

// utils_stack.c
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_highest_node(t_stack_node *stack);
t_stack_node	*find_lowest_node(t_stack_node *stack);
t_stack_node	*find_second_lowest_node(t_stack_node *stack);
int				ft_stack_len(t_stack_node *stack);

/********************************* FT_SORTING ******************************/

// prep_and_costs.c
void			ft_current_position(t_stack_node *stack);
void			ft_find_target_for_b(t_stack_node *a, t_stack_node *b);
void			ft_calc_moves(t_stack_node *stack_1, t_stack_node *stack_2);
void			ft_prep_for_push(t_stack_node **a, t_stack_node **b);
void			ft_prep_for_comeback(t_stack_node *a, t_stack_node *b);

// mini_sort.c
void			ft_mini_sort_3(t_stack_node	**stack);
void			ft_mini_sort_5(t_stack_node **stack_1, t_stack_node **stack_2);

// pivot_and_partitioning.c
void			ft_part_stack(t_stack_node **a, t_stack_node **b);

// sorting_alg.c
void			ft_sorting_alg(t_stack_node **a, t_stack_node **b);
void			ft_big_sort(t_stack_node **a, t_stack_node **b);

// utils_sort.c
bool			ft_is_stack_sorted(t_stack_node *stack);
void			ft_set_cheapest(t_stack_node *stack);
t_stack_node	*ft_find_cheapest_node(t_stack_node *stack);
void			ft_lowest_on_top(t_stack_node **a);

#endif
