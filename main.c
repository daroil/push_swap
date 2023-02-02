/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/02/02 14:13:41 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chckleaks(void)
{
	system("leaks push_swap");
}

char	**get_args(int argc, char **argv)
{
	char	**result;
	int		i;

	i = 0;
	if (argc == 2 && !all_digits(argv + 1))
		result = ft_split(argv[1], ' ');
	else
	{
		while (argv[i])
			i++;
		result = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (argv[++i])
		{
			result[i - 1] = ft_strdup(argv[i]);
			if (!result[i - 1][0])
				return (free_split(result), NULL);
		}
	}
	if (!all_digits(result) || !all_int(result))
	{
		free_split(result);
		return (NULL);
	}
	return (result);
}

void	sort(t_push_list **head_a, t_push_list **head_b)
{
	t_push_list	*a;
	t_push_list	*b;

	a = *head_a;
	b = *head_b;
	initial_swap(&a);
	while (b)
	{
		steps(a, b);
		push_best_b_to_a(&a, &b, a, b);
	}
	final_rotate(&a);
	*head_a = a;
	*head_b = b;
}

int	you_died(t_push_list **stack_a, t_push_list **stack_b,
		char **args, char *exit_message)
{
	ft_push_clear(stack_a);
	ft_push_clear(stack_b);
	ft_putstr_fd(exit_message, 1);
	free_split(args);
	return (0);
}

int		ft_max(t_push_list *s)
{
	int max;

	max = s->number;
	while (s)
	{
		if (s->number > max)
			max = s->number;
		s = s->next;
	}
	return (max);
}

int		ft_min(t_push_list *s)
{
	int min;

	min = s->number;
	while (s)
	{
		if (s->number < min)
			min = s->number;
		s = s->next;
	}
	return (min);
}

void	ft_sort_3_element(t_push_list **stack_a)
{
	int max;

	max = ft_max(*stack_a);
	if (stck_len(*stack_a) == 1)
		return ;
	else if (stck_len(*stack_a) == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
		return ;
	}
	else if (stck_len(*stack_a) == 3)
	{
		if ((*stack_a)->number == max)
			ra(stack_a);
		if ((*stack_a)->next->number == max)
			rra(stack_a);
		if ((*stack_a)->number > (*stack_a)->next->number)
			sa(stack_a);
	}
}

void	ft_sort_5_element(t_push_list **stack_a, t_push_list **stack_b)
{
	int	min;
	int max;

	min = ft_min(*stack_a);
	max = ft_max(*stack_a);
	while (stck_len(*stack_b) < 2)
	{
		if ((*stack_a)->number == min || (*stack_a)->number == max)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_sort_3_element(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->number == max)
		ra(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

int	choose_and_sort(int i, t_push_list **stack_a, t_push_list **stack_b)
{
	if (i == 3)
		ft_sort_3_element(stack_a);
	else if (i == 5)
		ft_sort_5_element(stack_a, stack_b);
	else
	{
		push_most_to_b(stack_a, stack_b);
		if ((*stack_a)->steps == -1)
		return (0);
		sort(stack_a, stack_b);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	t_push_list	*stack_a;
	t_push_list	*stack_b;
	char		**arguements;

	if (argc < 2)
		return (0);
	arguements = get_args(argc, argv);
	if (!arguements)
		return (you_died(NULL, NULL, NULL, "Error2\n"));
	i = 0;
	ft_lstadd_back_number(&stack_a, ft_atoi(arguements[i++]));
	if (!stack_a)
		return (you_died(NULL, NULL, NULL, "Error1\n"));
	while (arguements[i])
		ft_lstadd_back_number(&stack_a, ft_atoi(arguements[i++]));
	if (is_sorted(stack_a))
		return (you_died(&stack_a, &stack_b, arguements, ""));
	if (repeatitions(stack_a))
		return (you_died(&stack_a, &stack_b, arguements, "Error23\n"));
	if (!choose_and_sort(i, &stack_a, &stack_b))
		return (you_died(&stack_a, &stack_b, arguements, "Error3\n"));	
	// push_most_to_b(&stack_a, &stack_b);
	// if (stack_a->steps == -1)
	// 	return (you_died(&stack_a, &stack_b, arguements, "Error3\n"));
	// sort(&stack_a, &stack_b);
	// ft_sort_5_element(&stack_a, &stack_b);
	return (you_died(&stack_a, &stack_b, arguements, ""));
}
