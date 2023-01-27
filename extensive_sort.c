/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:54:54 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:56:08 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_b_rr_a(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = b->pos_b;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	iter = stck_len(a) - b->pos_a;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	rrb_ra(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(*head_b) - b->pos_b;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	iter = b->pos_a;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

int	find_index_of_min(push_list *stack)
{
	int	index;
	int	i;
	int	counter;

	i = MAX_INT;
	index = 0;
	counter = 0;
	while (stack)
	{
		if (stack->number < i)
		{
			i = stack->number;
			index = counter;
		}
		counter++;
		stack = stack->next;
	}
	return (index);
}

void	final_rotate(push_list **stack_a)
{
	int		index;

	index = find_index_of_min(*stack_a);
	if (index < stck_len(*stack_a) - index)
	{
		while (index--)
			ra(stack_a);
	}
	else
	{
		index = stck_len(*stack_a) - index;
		while (index--)
			rra(stack_a);
	}
}