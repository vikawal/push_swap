/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:53:19 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 12:01:26 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		highest;

	tmp = *stack;
	highest = tmp->value;
	while (tmp)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	if ((*stack)->value == highest)
		ra(stack);
	else if ((*stack)->next->value == highest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_all(t_stack **a, t_stack **b)
{
	save_three_a(a, b, stack_size(*a));
	while (*b)
	{
		target_position(a, b);
		cost(a, b);
		cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		final_offset(a);
}
