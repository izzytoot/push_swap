/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:28:31 by root              #+#    #+#             */
/*   Updated: 2025/01/07 17:48:36 by icunha-t         ###   ########.fr       */
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
	bool				chunk_start;
	bool				chunk_end;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* ************************************************************************** */
/*                                  VARIABLES                                 */
/* ************************************************************************** */
static int	chunck_position = -1;

/* ************************************************************************** */
/*                                  FUNCTIONS                                 */
/* ************************************************************************** */

/********************************* FT_COMMANDS ********************************/

// c_push.c
void			pa(t_stack_node **a, t_stack_node **b, bool check);
void			pb(t_stack_node **b, t_stack_node **a, bool check);
// c_reverse_rotate.c
void			rra(t_stack_node **a, bool check);
void			rrb(t_stack_node **b, bool check);
void			rrr(t_stack_node **a, t_stack_node **b, bool check);
// c_rotate.c
void			ra(t_stack_node **a, bool check);
void			rb(t_stack_node **b, bool check);
void			rr(t_stack_node **a, t_stack_node **b, bool check);
// c_swap.c
void			sa(t_stack_node **a, bool check);
void			sb(t_stack_node **b, bool check);
void			ss(t_stack_node **a, t_stack_node **b, bool check);

/********************************** FT_INIT *********************************/

// error_handling.c
int				ft_error_char(char *str);
int				ft_error_repeat(t_stack_node *stack, int n);
void			ft_free_errors(t_stack_node **a);
void			ft_free_stack(t_stack_node **stack);

//split.c
char			**split(char *str, char c);

// stack_init.c
void			ft_stack_init(t_stack_node **a, char **av);
void			ft_append_node(t_stack_node **stack, int n);

// utils_stack.c
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_highest_node(t_stack_node *stack);
t_stack_node	*find_lowest_node(t_stack_node *stack);
t_stack_node	*find_second_lowest_node(t_stack_node *stack);
int				ft_stack_len(t_stack_node *stack);

/********************************* FT_SORTING ******************************/

// costs.c
void		ft_find_best_insert(t_stack_node **a, t_stack_node **b);
int			ft_find_cheapest(t_stack_node **a, t_stack_node **b, int start, int current_len);
int			ft_calculate_moves(t_stack_node **a, t_stack_node **b, int	current);
int			ft_find_distance(t_stack_node **stack, int	nbr);
int			ft_find_next(t_stack_node **stack, int nbr);
int			*ft_which_item(t_stack_node *stack, int i);

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
int				ft_abs(int	n);

// OUTROS
int				*ft_stack_cpy(t_stack_node *stack, int size);
void			print_stack(t_stack_node *stack, char *name);

#endif
