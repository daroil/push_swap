/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:32:36 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:07:08 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_list **stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_list **stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_list **stack_a, t_push_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

void	rotate(t_push_list **stack)
{
	t_push_list	*first;
	t_push_list	*second;
	t_push_list	*last;

	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast_push(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
}
