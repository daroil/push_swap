/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/23 19:48:03 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chckleaks(void)
{
	system("leaks push_swap");
}

push_list	*ft_lstlast_push(push_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}


void	ft_lstadd_number(push_list **lst, int number)
{
	push_list *new;
	
	// new = NULL;
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

void	ft_push_clear(push_list **lst)
{
	push_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone_push(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	stck_size(push_list *stack)
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

void	swap(push_list **stack)
{
	push_list	*first;
	push_list	*second;
	push_list	*third;

	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	*stack = second;
	second->next = first;
	first->next = third;
	printf("swapped\n");
}

void	push(push_list **source, push_list **dest)
{
	if (!*source)
		return ;
	
}

int main(int argc, char **argv)
{
	int	i;
	push_list	*stack_a;
	push_list	*tmp;

	atexit(chckleaks);
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back_number(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	i = 0;
	tmp = stack_a;
	while (stack_a->next)
	{
		printf("integer %d:%d \n", i, stack_a->number);
		i++;
		stack_a = stack_a->next;
	}
	printf("integer %d:%d \n", i, stack_a->number);
	stack_a = tmp;
	swap(&stack_a);
	tmp = stack_a;
	i = 0;
	while (stack_a->next)
	{
		printf("integer %d:%d \n", i, stack_a->number);
		i++;
		stack_a = stack_a->next;
	}
	printf("integer %d:%d \n", i, stack_a->number);
	i = 0;
	while (i < argc)
	{
		printf("i:%d arguement:%s\n",i,argv[i]);
		i++;
	}
	ft_push_clear(&tmp);
	return (0);
}