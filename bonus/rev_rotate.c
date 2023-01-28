/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:33:26 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 05:17:02 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rev_rotate(t_push_list **stack)
{
	t_push_list	*first;
	t_push_list	*second_to_last;
	t_push_list	*last;

	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	last = ft_lstlast_push(*stack);
	second_to_last = ft_lst_second_to_last_push(*stack);
	last->next = first;
	*stack = last;
	second_to_last->next = NULL;
}

void	rra(t_push_list **stack)
{
	rev_rotate(stack);
}

void	rrb(t_push_list **stack)
{
	rev_rotate(stack);
}

void	rrr(t_push_list **stack_a, t_push_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
