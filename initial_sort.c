/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:47:32 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:50:18 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_most_to_b(push_list **stack_a, push_list **stack_b)
{
	int	*min_max_med;

	min_max_med = find_min_med_max(*stack_a);
	while (stck_len(*stack_a) > 3)
	{
		if ((*stack_a)->number != min_max_med[0]
			&& (*stack_a)->number != min_max_med[1]
			&& (*stack_a)->number != min_max_med[2])
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	free(min_max_med);
}

void	initial_swap(push_list **head_a)
{
	push_list	*a;

	if (stck_size(*head_a) != 3)
		return ;
	a = *head_a;
	if ((a->number < a->next->number && a->number < a->next->next->number
			&& a->next->number > a->next->next->number)
		|| (a->number > a->next->number
			&& a->number < a->next->next->number
			&& a->next->number < a->next->next->number)
		|| (a->number > a->next->number && a->number > a->next->next->number
			&& a->next->number > a->next->next->number))
		sa(head_a);
}

int	stck_len(push_list *stack)
{
	push_list	*temp;
	int		res;

	res = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

void	push_best_b_to_a(push_list **stack_a, push_list **stack_b, push_list *a, push_list *b)
{
	int		min_steps;

	min_steps = find_min_steps(b);
	while (stack_a)
	{	
		if (b->steps == min_steps)
		{
			if (min_steps == max(b->pos_a, b->pos_b) + 1)
				rotate_then_push(b, stack_a, stack_b);
			else if (min_steps == max(stck_len(a)
					- b->pos_a, stck_len(*stack_b) - b->pos_b) + 1)
				rev_rotate_then_push(a, b, stack_a, stack_b);
			else if (min_steps == b->pos_b + stck_len(a) - b->pos_a + 1)
				rot_b_rr_a(a, b, stack_a, stack_b);
			else if (min_steps == b->pos_a
				+ stck_len(*stack_b) - b->pos_b + 1)
				rrb_ra(b, stack_a, stack_b);
			return ;
		}
		b = b->next;
	}
}