/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:39:14 by vmyshko           #+#    #+#             */
/*   Updated: 2024/02/16 15:31:44 by vmyshko          ###   ########.fr       */
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
//(reverse rotate a): Shift down all elements of stack by 1.
//The last element becomes the first one.
// 
static void	rotate_back_reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = stack_last(*stack);
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	*stack = last;
	(*stack)->next = tmp;
	before_last->next = NULL;
}

void	rra(t_stack **stack_a)
{
	rotate_back_reverse(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	rotate_back_reverse(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_back_reverse(stack_a);
	rotate_back_reverse(stack_b);
	ft_putendl_fd("rrr", 1);
}
