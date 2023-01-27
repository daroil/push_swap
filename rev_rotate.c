/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:33:26 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:33:59 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rev_rotate(push_list **stack)
{
	push_list	*first;
	push_list	*second_to_last;
	push_list	*last;
	
	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	last = ft_lstlast_push(*stack);
	second_to_last = ft_lst_second_to_last_push(*stack);
	last->next = first;
	*stack = last;
	second_to_last->next = NULL;
}

void	rra(push_list **stack)
{
	rev_rotate(stack);
	ft_putstr_fd("rra\n",1);
}

void	rrb(push_list **stack)
{
	rev_rotate(stack);
	ft_putstr_fd("rrb\n",1);
}

void	rrr(push_list **stack_a, push_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr_fd("rrr\n",1);
}