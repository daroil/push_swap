/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:31:43 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:32:30 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(push_list **stack)
{
	push_list	*first;
	push_list	*second;
	push_list	*third;

	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	*stack = second;
	second->next = first;
	first->next = third;
}

void	sa(push_list **stack)
{
	swap(stack);
	ft_putstr_fd("sa\n",1);
}

void	sb(push_list **stack)
{
	swap(stack);
	ft_putstr_fd("sb\n",1);
}

void	ss(push_list **stack_a, push_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n",1);
}