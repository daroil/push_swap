/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:08 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 22:48:26 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pb(push_list **stack_a, push_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n",1);
}

void	pa(push_list **stack_a, push_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n",1);
}

void	ra(push_list **stack)
{
	rotate(stack);
	ft_putstr_fd("ra\n",1);
}

void	rb(push_list **stack)
{
	rotate(stack);
	ft_putstr_fd("rb\n",1);
}

void	rr(push_list **stack_a, push_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n",1);
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
