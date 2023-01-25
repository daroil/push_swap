/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:07:13 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:22:16 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finish(t_list *head_a, t_list *head_b, char **other_var, char *exit_message)
{
	free_list(head_a);
	free_list(head_b);
	ft_putstr(exit_message);
	free_split(other_var);
	return (0);
}

int	check_if_stack_sorted(t_list *head)
{
	long	i;

	i = MIN_INT - 1;
	while (head)
	{
		if (head->value <= i)
			return (0);
		i = head->value;
		head = head->next;
	}
	return (1);
}

int	start_sort(int argc, char **argv, int i)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**other_var;

	if (argc < 2)
		return (0);
	other_var = split_if_needed(argc, argv);
	if (!other_var)
		return (finish(NULL, NULL, NULL, "Error\n"));
	head_a = new_list(ft_atoi(other_var[i++]));
	head_b = NULL;
	if (!head_a)
		return (finish(head_a, head_b, other_var, "Error\n"));
	while (other_var[i])
		add_back(head_a, new_list(ft_atoi(other_var[i++])));
	if (check_if_stack_sorted(head_a))
		return (finish(head_a, NULL, other_var, ""));
	if (check_repetitions(head_a) == 0)
		return (finish(head_a, head_b, other_var, "Error\n"));
	head_b = push_b(&head_a);
	if (head_a->steps == -1)
		return (finish(head_a, head_b, other_var, "Error\n"));
	sort(&head_a, &head_b);
	return (finish(head_a, head_b, other_var, ""));
}

int	main(int argc, char **argv)
{
	start_sort(argc, argv, 0);
}
