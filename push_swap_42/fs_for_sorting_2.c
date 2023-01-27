/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_for_sorting_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:09 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 22:44:09 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f6(t_list *b, t_list **head_a, t_list **head_b)
{
	int	iter;

	iter = list_len(*head_b) - b->cur_pos_b;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	iter = b->cur_pos_a;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	f7(t_list *b, t_list **head_a, t_list **head_b)
{
	if (b->cur_pos_a < b->cur_pos_b)
		f1(b, head_a, head_b);
	else
		f2(b, head_a, head_b);
}

void	f8(t_list *a, t_list *b, t_list **head_a, t_list **head_b)
{
	if (list_len(a) - b->cur_pos_a
		< list_len(*head_b) - b->cur_pos_b)
		f3(a, b, head_a, head_b);
	else
		f4(b, head_a, head_b);
}

int	count_steps(int cur_pos_b, int cur_pos_a,
	t_list *head_b, t_list *temp)
{
	return (min(min(max(cur_pos_b, cur_pos_a),
				max(list_len(head_b), list_len(temp))),
			min(cur_pos_b + list_len(temp),
				cur_pos_a + list_len(head_b))) + 1);
}

void	set_pos_count_steps(t_list *head_b, t_list *temp,
	int cur_pos_a, int cur_pos_b)
{
	head_b->steps = count_steps(cur_pos_b, cur_pos_a, head_b, temp);
	printf("steps %d\n",head_b->steps);
	head_b->cur_pos_a = cur_pos_a;
	head_b->cur_pos_b = cur_pos_b;
}
