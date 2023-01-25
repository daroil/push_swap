/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:57 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:32:59 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	push_first_from_b_to_a(head_a, head_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **head_a, t_list **head_b)
{
	push_first_from_b_to_a(head_b, head_a);
	write(1, "pb\n", 3);
}
