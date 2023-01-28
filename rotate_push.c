/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:51:30 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:09:32 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_then_push(t_push_list *b,
	t_push_list **head_a, t_push_list **head_b)
{
	if (b->pos_a < b->pos_b)
		pos_a(b, head_a, head_b);
	else
		pos_b(b, head_a, head_b);
}

void	pos_a(t_push_list *b, t_push_list **head_a, t_push_list **head_b)
{
	int	iter;

	iter = b->pos_a;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->pos_b - b->pos_a;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	pos_b(t_push_list *b, t_push_list **head_a, t_push_list **head_b)
{
	int	iter;

	iter = b->pos_b;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->pos_a - b->pos_b;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}
