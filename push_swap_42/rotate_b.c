/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:57:26 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:57:29 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rrb(t_list **head)
{
	rotate_reverse(head);
	write(1, "rrb\n", 4);
}
