/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:17:08 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:34:59 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(push_list **source, push_list **dest)
{
	push_list	*first_source;
	push_list	*first_dest;
	push_list	*second_source;
	
	if (!*source)
		return ;
	first_dest = *dest;
	first_source = *source;
	second_source = (*source)->next;
	first_source->next = first_dest;
	*dest =  first_source;
	*source = second_source;
}

void	pb(push_list **stack_a, push_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n",1);
}

void	pa(push_list **stack_a, push_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n",1);
}

