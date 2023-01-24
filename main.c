/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/24 15:11:03 by dhendzel         ###   ########.fr       */
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
	printf("pushed\n");
}

void	rotate(push_list **stack)
{
	push_list	*first;
	push_list	*second;
	push_list	*last;
	
	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = ft_lstlast_push(*stack);
	last->next = first;
	first->next = NULL;
	*stack = second;
	printf("rotated\n");
}

void	rev_rotate(push_list **stack)
{
	push_list	*first;
	push_list	*second_to_last;
	push_list	*last;
	
	if (stck_size(*stack) < 2)
		return ;`
	first = *stack;
	last = ft_lstlast_push(*stack);
	second_to_last = ft_lst_second_to_last_push(*stack);
	last->next = first;
	*stack = last;
	second_to_last->next = NULL;
	printf("reverse rotated\n");
}

int main(int argc, char **argv)
{
	int	i;
	push_list	*stack_a;
	push_list	*stack_b;
	push_list	*tmp;
	push_list	*tmp_b;

	atexit(chckleaks);
	if (!argc)
		return (0);
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
	push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// rotate(&stack_a);
	rev_rotate(&stack_a);
	// rotate(&stack_b);
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
	tmp_b = stack_b;
	while (stack_b->next)
	{
		printf("integer stack b %d:%d \n", i, stack_b->number);
		i++;
		stack_b = stack_b->next;
	}
	printf("integer stack b %d:%d \n", i, stack_b->number);
	ft_push_clear(&tmp);
	ft_push_clear(&tmp_b);
	return (0);
}