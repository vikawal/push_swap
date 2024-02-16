/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:34:08 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 15:30:05 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//from bonus_libft
//finding last element in the list
// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst -> next != NULL)
// 		lst = lst -> next;
// 	return (lst);
// }
// Shift up all elements of stack by 1: moving the top element to the bottom.
//The first element becomes the last one.
//stack: 1 -> 2 -> 3 -> NULL

static void	rotate_forward(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = stack_last(*stack);
	last->next = tmp;
	tmp->next = NULL;
}

//(rotate a): Shift up all elements of stack A by 1.
//The first element becomes the last one.

void	ra(t_stack **stack_a)
{
	rotate_forward(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate_forward(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_forward(stack_a);
	rotate_forward(stack_b);
	ft_putendl_fd("rr", 1);
}
