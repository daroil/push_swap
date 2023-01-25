/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:33:03 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:33:05 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head)
{
	swap_first_two(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap_first_two(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap_first_two(head_b);
	swap_first_two(head_a);
	write(1, "ss\n", 3);
}
