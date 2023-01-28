/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:08 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:10:24 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_push_list **source, t_push_list **dest)
{
	t_push_list	*first_source;
	t_push_list	*first_dest;
	t_push_list	*second_source;

	if (!*source)
		return ;
	first_dest = *dest;
	first_source = *source;
	second_source = (*source)->next;
	first_source->next = first_dest;
	*dest = first_source;
	*source = second_source;
}

void	pb(t_push_list **stack_a, t_push_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_push_list **stack_a, t_push_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}
