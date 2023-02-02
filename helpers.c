/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:41:57 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/30 12:56:06 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	res *= sign;
	if (res > MAX_INT || res < MIN_INT)
		return (0);
	return (1);
}

int	all_int(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (!check_int(result[i]))
			return (0);
		i++;
	}
	return (1);
}

t_push_list	*get_last(t_push_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_push_clear(t_push_list **lst)
{
	t_push_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_push(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	stck_size(t_push_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
