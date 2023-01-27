/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:30:15 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:30:30 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

push_list	*ft_lstlast_push(push_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

push_list	*ft_lst_second_to_last_push(push_list *lst)
{
	if (!lst)
		return (NULL);
	while ((lst->next)->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_number(push_list **lst, int number)
{
	push_list *new;
	
	new = malloc(sizeof(push_list));
	if (!new)
		return ;
	new->next = *lst;
	new->number = number;
	*lst = new;
}

void	ft_lstadd_back_number(push_list **lst, int number)
{
	push_list	*tmp;
	push_list 	*new;

	new = malloc(sizeof(push_list));
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->number = number;
		return ;
	}
	new->number = number;
	tmp = ft_lstlast_push(*lst);
	tmp->next = new;
}

void	ft_lstdelone_push(push_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}