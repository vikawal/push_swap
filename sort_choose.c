/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:52 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 16:46:32 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

static void	position(t_stack *stack);
static int	target(t_stack **a, int b_index);
static int	botton_target(t_stack **a, int target_index, int target_pos);

// determining the position of the element with the 
//lowest index in a given stack.
//Then, it iterates through the stack to find the 
//element with the lowest index. 
//It updates lower_index and lower_pos accordingly.
int	lower_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lower_index;
	int		lower_pos;

	position(*stack);
	tmp = *stack;
	lower_index = INT_MAX;
	lower_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lower_index)
		{
			lower_index = tmp->index;
			lower_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lower_pos);
}
//assigning target positions in stack A for each element in stack B.
// It first assigns positions to each element of both stacks 
// Then, it iterates through stack B to assign target positions 
//for each element.
// For each element in stack B, it calls the target function to determine 
//the best target position in stack A based on the element's index. 
//It assigns this target position to 
//the target_pos attribute of the corresponding element in stack B.

void	target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	position(*a);
	position(*b);
	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->target_pos = target(a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}
/* get_position:
*	Assigns a position to each element of a stack from top to bottom
*	in ascending order.
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*	This is used to calculate the cost of moving a certain number to
*	a certain position. If the above example is stack b, it would cost
*	nothing (0) to push the first element to stack a. However if we want to
*	push the highest value, 9, which is in third position, it would cost 2 extra
*	moves to bring that 9 to the top of b before pushing it to stack a.
*/

static void	position(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack)
	{
		stack->pos = ++i;
		stack = stack->next;
	}
}
// The target function iterates through stack A to find the element with 
// the index closest to but greater than the index of the element in stack B. 
//If no such element is found, it calls the botton_target function to find 
//the element with the lowest index in stack A.
//   The botton_target function simply iterates through stack A to find the 
//element with the lowest index.

// These functions help determine the best target position in stack A 
//for pushing elements from stack B, considering the indices of elements 
//in both stacks.
static int	target(t_stack **a, int b_index)
{
	t_stack	*tmp_a;
	int		target_index;
	int		target_pos;

	tmp_a = *a;
	target_index = INT_MAX;
	target_pos = 0;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	else
		return (botton_target(a, target_index, target_pos));
}

static int	botton_target(t_stack **a, int target_index, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_index)
		{
			target_index = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}
