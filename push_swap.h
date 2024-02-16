/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:22:18 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 13:55:18 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include "LIBFT/libft.h"

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <memory.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//error Macros
# define ERR_STACK "error stack"

//utils
void				free_stack(t_stack **stack);
void				ft_error(char *msg, t_stack **stack_a, t_stack **stack_b);
int					is_sorted(t_stack *stack);
void				ft_memfree_all(char **ptr);

// check_args
t_stack				*ft_check_args(int argc, char **argv);
int					ft_check_arg_dup(t_stack *stack_a);
int					ft_is_digit_sign(char **str, int i);
//stack
t_stack				*stack_last(t_stack *lst);
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *stack_new);
int					stack_size(t_stack *stack);
// algorithm
void				sort_three(t_stack **stack);
void				sort_all(t_stack **a, t_stack **b);
// algorithm utils
void				save_three_a(t_stack **a, t_stack **b, int size);
void				cost(t_stack **stack_a, t_stack **stack_b);
void				cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				final_offset(t_stack **stack_a);
//move
void				move(t_stack **a, t_stack **b, int cost_a, int cost_b);
//position
int					lower_position(t_stack **stack);
void				target_position(t_stack **a, t_stack **b);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif