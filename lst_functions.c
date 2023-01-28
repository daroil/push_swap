/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:30:15 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:12:07 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_list	*ft_lstlast_push(t_push_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_push_list	*ft_lst_second_to_last_push(t_push_list *lst)
{
	if (!lst)
		return (NULL);
	while ((lst->next)->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_number(t_push_list **lst, int number)
{
	t_push_list	*new;

	new = malloc(sizeof(t_push_list));
	if (!new)
		return ;
	new->next = *lst;
	new->number = number;
	*lst = new;
}

void	ft_lstadd_back_number(t_push_list **lst, int number)
{
	t_push_list	*tmp;
	t_push_list	*new;

	new = malloc(sizeof(t_push_list));
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

void	ft_lstdelone_push(t_push_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
