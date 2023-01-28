/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:32:36 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 05:16:55 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ra(t_push_list **stack)
{
	rotate(stack);
}

void	rb(t_push_list **stack)
{
	rotate(stack);
}

void	rr(t_push_list **stack_a, t_push_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
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
