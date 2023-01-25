/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:47:26 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 19:48:11 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	list_len(t_list *head)
{
	t_list	*temp;
	int		res;

	res = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

int	check_if_stack_sorted(t_list *head)
{
	long	i;

	i = MIN_INT - 1;
	while (head)
	{
		if (head->value <= i)
			return (0);
		i = head->value;
		head = head->next;
	}
	return (1);
}

int	finish(t_list *head_a, t_list *head_b, char **other_var, int return_value)
{
	if (head_a)
		free_list(head_a);
	if (head_b)
		free_list(head_b);
	if (other_var)
		free_split(other_var);
	return (return_value);
}
