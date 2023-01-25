/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:28 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 19:00:30 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_min_med_max(t_list *temp)
{
	int		minim;
	int		maxim;
	int		*res;

	res = malloc(sizeof(int) * 3);
	if (!res)
		return (NULL);
	minim = MAX_INT;
	maxim = MIN_INT;
	while (temp)
	{
		if (temp->value > maxim)
			maxim = temp->value;
		if (temp->value < minim)
			minim = temp->value;
		temp = temp->next;
	}
	res[0] = minim;
	res[2] = maxim;
	res[1] = find_median(temp);
	return (res);
}

t_list	*push_b(t_list **head_a)
{
	t_list	*head_b;
	t_list	*other_temp;
	t_list	*yet_another_temp;
	int		*min_med_max;

	other_temp = *head_a;
	min_med_max = find_min_med_max(*head_a);
	if (!min_med_max)
		return (NULL);
	head_b = NULL;
	yet_another_temp = NULL;
	if ((*head_a)->steps == -1)
		return (NULL);
	while (list_len(other_temp) > 3)
	{
		if (other_temp->value != min_med_max[0]
			&& other_temp->value != min_med_max[2]
			&& other_temp->value != min_med_max[1])
			pb(&other_temp, &head_b);
		else
			ra(&other_temp);
	}
	*head_a = other_temp;
	free(min_med_max);
	return (head_b);
}
