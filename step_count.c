/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:39:04 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:06:59 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_steps(int cur_pos_b, int cur_pos_a,
	t_push_list *stack_b, t_push_list *stack_a)
{
	return (min(min(max(cur_pos_b, cur_pos_a),
				max(stck_len(stack_b), stck_len(stack_a))),
			min(cur_pos_b + stck_len(stack_a),
				cur_pos_a + stck_len(stack_b))) + 1);
}

void	set_pos_count_steps(t_push_list *stack_b, t_push_list *stack_a,
	int cur_pos_a, int cur_pos_b)
{
	stack_b->steps = count_steps(cur_pos_b, cur_pos_a, stack_b, stack_a);
	stack_b->pos_a = cur_pos_a;
	stack_b->pos_b = cur_pos_b;
}

void	steps(t_push_list *stack_a, t_push_list *head_b)
{
	int			cur_pos_a;
	int			cur_pos_b;
	t_push_list	*temp;

	cur_pos_b = 0;
	while (head_b)
	{
		temp = stack_a;
		if ((get_last(temp)->number < head_b->number)
			&& (temp->number > head_b->number))
			set_pos_count_steps(head_b, temp, 0, cur_pos_b);
		cur_pos_a = 1;
		while (temp->next)
		{
			if ((temp->number < head_b->number)
				&& (temp->next->number > head_b->number))
				set_pos_count_steps(head_b, temp->next, cur_pos_a, cur_pos_b);
			temp = temp->next;
			cur_pos_a++;
		}
		head_b = head_b->next;
		cur_pos_b++;
	}
}

int	find_min_steps(t_push_list *stack)
{
	int	min_steps;

	min_steps = MAX_INT;
	while (stack)
	{
		if (stack->steps < min_steps)
			min_steps = stack->steps;
		stack = stack->next;
	}
	return (min_steps);
}
