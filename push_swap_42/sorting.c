/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:00 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 22:36:40 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_best_b_to_a(t_list **head_a, t_list **head_b, t_list *a, t_list *b)
{
	int		min_steps;

	min_steps = find_min_steps(b);
	while (head_a)
	{	
			printf("b->steps %d\n",b->steps);
		if (b->steps == min_steps)
		{
			if (min_steps == max(b->cur_pos_a, b->cur_pos_b) + 1)
				f7(b, head_a, head_b);
			else if (min_steps == max(list_len(a)
					- b->cur_pos_a, list_len(*head_b) - b->cur_pos_b) + 1)
				f8(a, b, head_a, head_b);
			else if (min_steps == b->cur_pos_b + list_len(a) - b->cur_pos_a + 1)
				f5(a, b, head_a, head_b);
			else if (min_steps == b->cur_pos_a
				+ list_len(*head_b) - b->cur_pos_b + 1)
				f6(b, head_a, head_b);
			return ;
		}
		b = b->next;
	}
}

int	find_index_of_min(t_list *temp)
{
	int	index;
	int	i;
	int	counter;

	i = MAX_INT;
	index = 0;
	counter = 0;
	while (temp)
	{
		if (temp->value < i)
		{
			i = temp->value;
			index = counter;
		}
		counter++;
		temp = temp->next;
	}
	return (index);
}

void	final_rotate(t_list **head_a)
{
	t_list	*temp;
	int		index;

	temp = *head_a;
	index = find_index_of_min(temp);
	if (index < list_len(*head_a) - index)
	{
		while (index--)
			ra(head_a);
	}
	else
	{
		index = list_len(*head_a) - index;
		while (index--)
			rra(head_a);
	}
}

void	initial_swap(t_list **head_a)
{
	t_list	*a;

	if (list_len(*head_a) != 3)
		return ;
	a = *head_a;
	if ((a->value < a->next->value && a->value < a->next->next->value
			&& a->next->value > a->next->next->value)
		|| (a->value > a->next->value
			&& a->value < a->next->next->value
			&& a->next->value < a->next->next->value)
		|| (a->value > a->next->value && a->value > a->next->next->value
			&& a->next->value > a->next->next->value))
		sa(head_a);
}

void	sort(t_list **head_a, t_list **head_b)
{
	t_list	*a;
	t_list	*b;

	a = *head_a;
	b = *head_b;
	initial_swap(&a);
	while (b)
	{
	printf("value of head b%d\n",b->value);
		steps(a, b);
		push_best_b_to_a(&a, &b, a, b);
	}
	final_rotate(&a);
	*head_a = a;
	*head_b = b;
}
