/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:27:29 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:13:18 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*find_min_med_max(t_push_list *temp)
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
		if (temp->number > maxim)
			maxim = temp->number;
		if (temp->number < minim)
			minim = temp->number;
		temp = temp->next;
	}
	res[0] = minim;
	res[2] = maxim;
	res[1] = get_median(temp);
	return (res);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	get_median(t_push_list *stack)
{
	int	median;
	int	size;
	int	*array;
	int	i;

	i = 0;
	size = stck_size(stack);
	array = malloc(sizeof(int) * size);
	if (!array)
	{
		stack->steps = -1;
		return (0);
	}
	while (stack)
	{
		array[i] = stack->number;
		i++;
		stack = stack->next;
	}	
	sort_int_tab(array, size);
	median = array[i / 2];
	free(array);
	return (median);
}
