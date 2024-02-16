/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1_sa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:42:23 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 15:18:12 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// wap the first 2 elements at the top of stack should be static void
static void	ft_swap_1_2(t_stack **stack)
{
	t_stack	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
//1 -> 2 -> 3 -> 4 -> NULL
// update the original list pointer to point to the second element
//(which originally held 1) to point to the node following 
//the new first node (2).
// 1 -> 3 -> 4 -> NULL 
//update the "next" pointer of the new first node (2)
//to point to our temporary box, which holds the original first node (1).

// sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	sa(t_stack **stack_a)
{
	ft_swap_1_2(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	ft_swap_1_2(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_1_2(stack_a);
	ft_swap_1_2(stack_b);
	ft_putendl_fd("ss", 1);
}
