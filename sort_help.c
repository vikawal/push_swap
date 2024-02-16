/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:59:22 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 16:48:30 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

/* 
*	Push all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
void	save_three_a(t_stack **a, t_stack **b, int size)
{
	while (stack_size(*b) < size / 2 && stack_size(*a) > 3)
	{
		if ((*a)->index <= size / 2)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
}

// prepares the costs associated with moving elements between stacks, 
//considering their positions and target positions
// for stack b to move it to a, and in stack a - to put it on ideal position
void	cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > stack_size(*b) / 2)
			tmp->cost_b = (stack_size(*b) - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > stack_size(*a) / 2)
			tmp->cost_a = (stack_size(*a) - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}

//iterates through stack B to calculate the total cost for each element 
//and find the cheapest move.
//For each element, it calculates the total cost as 
//the sum of the absolute values 
//of cost_a and cost_b, representing the costs associated 
//with moving the element 
//from stack B to stack A and then to its target position in stack A.
void	cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_iabs(tmp->cost_a) + ft_iabs(tmp->cost_b) < ft_iabs(cheapest))
		{
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
			cheapest = ft_iabs(cost_b) + ft_iabs(cost_a);
		}
		tmp = tmp->next;
	}
	move(a, b, cost_a, cost_b);
}
// adjusts the position of the element with the lowest 
//index in stack A to either the bottom or the top of the stack,
//depending on its current position relative to the midpoint of the stack

void	final_offset(t_stack **a)
{
	int	lower_pos;

	lower_pos = lower_position(a);
	if (lower_pos > stack_size(*a) / 2)
	{
		while (lower_pos < stack_size(*a))
		{
			rra(a);
			lower_pos++;
		}
	}
	else
	{
		while (lower_pos > 0)
		{
			ra(a);
			lower_pos--;
		}
	}
}

// int	ft_is_digit_sign(char **str, int i)
// {
// 	int	j;

// 	j = 0;
// 	if (ft_is_sign(str[i][j]))
// 		j++;
// 	while (str[i][j])
// 	{
// 		if (!ft_isdigit(str[i][j]))
// 			return (0);
// 		j++;
// 	}
// 	return (1);
// }