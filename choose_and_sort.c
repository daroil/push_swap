/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_and_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:34:31 by dhendzel          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:31 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_push_list *s)
{
	int	max;

	max = s->number;
	while (s)
	{
		if (s->number > max)
			max = s->number;
		s = s->next;
	}
	return (max);
}

int	ft_min(t_push_list *s)
{
	int	min;

	min = s->number;
	while (s)
	{
		if (s->number < min)
			min = s->number;
		s = s->next;
	}
	return (min);
}

void	ft_sort_3_element(t_push_list **stack_a)
{
	int	max;

	max = ft_max(*stack_a);
	if (stck_len(*stack_a) == 1)
		return ;
	else if (stck_len(*stack_a) == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
		return ;
	}
	else if (stck_len(*stack_a) == 3)
	{
		if ((*stack_a)->number == max)
			ra(stack_a);
		if ((*stack_a)->next->number == max)
			rra(stack_a);
		if ((*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
	}
}

void	ft_sort_5_element(t_push_list **stack_a, t_push_list **stack_b)
{
	int	min;
	int	max;

	min = ft_min(*stack_a);
	max = ft_max(*stack_a);
	while (stck_len(*stack_b) < 2)
	{
		if ((*stack_a)->number == min || (*stack_a)->number == max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_sort_3_element(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->number == max)
		ra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	choose_and_sort(int i, t_push_list **stack_a, t_push_list **stack_b)
{
	if (i == 3)
		ft_sort_3_element(stack_a);
	else if (i == 5)
		ft_sort_5_element(stack_a, stack_b);
	else
	{
		push_most_to_b(stack_a, stack_b);
		if ((*stack_a)->steps == -1)
			return (0);
		sort(stack_a, stack_b);
	}
	return (1);
}
