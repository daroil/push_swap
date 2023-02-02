/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:43:33 by dhendzel          #+#    #+#             */
/*   Updated: 2023/02/02 14:37:31 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_sorted(t_push_list *stack)
{
	long	i;

	i = MIN_INT - 1;
	while (stack)
	{
		if (stack->number <= i)
			return (0);
		i = stack->number;
		stack = stack->next;
	}
	return (1);
}

int	inside_array(int *array, int number, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	repeatitions(t_push_list	*stack_a)
{
	int	*values;
	int	i;
	int	size;
	int	null_count;

	size = stck_len(stack_a);
	values = malloc(sizeof(int) * size);
	i = 0;
	null_count = 0;
	while (stack_a)
	{
		if (stack_a->number == 0)
			null_count++;
		if (inside_array(values, stack_a->number, size))
		{
			free(values);
			return (1);
		}
		values[i++] = stack_a->number;
		stack_a = stack_a->next;
	}
	free(values);
	return (0);
}

int	all_digits(char **argv)
{
	int	i;
	int	j;
	int	minus;

	i = 0;
	while (argv[i])
	{
		minus = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
					minus += 1;
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				return (0);
			if (minus > 1)
				return (0);
			j++;
		}
		if (minus && j == 1)
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
