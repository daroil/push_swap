/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:31:43 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:06:51 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push_list **stack)
{
	t_push_list	*first;
	t_push_list	*second;
	t_push_list	*third;

	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	*stack = second;
	second->next = first;
	first->next = third;
}

void	sa(t_push_list **stack)
{
	swap(stack);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_list **stack)
{
	swap(stack);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_list **stack_a, t_push_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
