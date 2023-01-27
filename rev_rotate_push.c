/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:52:28 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:52:50 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	b_is_bigger(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(a) - b->pos_a;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = stck_len(*head_b) - b->pos_b
		- stck_len(*head_a) + b->pos_a;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	a_is_bigger(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(*head_b) - b->pos_b;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = stck_len(*head_a) - b->pos_a
		- stck_len(*head_b) + b->pos_b;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	rev_rotate_then_push(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	if (stck_len(a) - b->pos_a
		< stck_len(*head_b) - b->pos_b)
		b_is_bigger(a, b, head_a, head_b);
	else
		a_is_bigger(b, head_a, head_b);
}