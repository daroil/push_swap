/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 01:11:39 by dhendzel         ###   ########.fr       */
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
		return (you_died(&stack_a, &stack_b, arguements, "Error\n"));
	push_most_to_b(&stack_a, &stack_b);
	if (stack_a->steps == -1)
		return (you_died(&stack_a, &stack_b, arguements, "Error3\n"));
	sort(&stack_a, &stack_b);
	return (you_died(&stack_a, &stack_b, arguements, ""));
}
