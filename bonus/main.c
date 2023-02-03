/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:16:55 by dhendzel          #+#    #+#             */
/*   Updated: 2023/02/03 15:42:35 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	you_lived(t_push_list **stack_a, t_push_list **stack_b,
		char **args, char *exit_message)
{
	ft_push_clear(stack_a);
	ft_push_clear(stack_b);
	ft_putstr_fd(exit_message, 1);
	free_split(args);
	return (0);
}

int	execute_instruction(t_push_list **stack_a, t_push_list **stack_b,
		char *inst)
{
	if (!ft_strncmp("sa\0", inst, 3))
		return (swap(stack_a), 0);
	else if (!ft_strncmp("sb\0", inst, 3))
		return (swap(stack_b), 0);
	else if (!ft_strncmp("ss\0", inst, 3))
		return (ss(stack_a, stack_b), 0);
	else if (!ft_strncmp("pa\0", inst, 3))
		return (pa(stack_a, stack_b), 0);
	else if (!ft_strncmp("pb\0", inst, 3))
		return (pb(stack_a, stack_b), 0);
	else if (!ft_strncmp("ra\0", inst, 3))
		return (ra(stack_a), 0);
	else if (!ft_strncmp("rb\0", inst, 3))
		return (rb(stack_b), 0);
	else if (!ft_strncmp("rr\0", inst, 3))
		return (rr(stack_a, stack_b), 0);
	else if (!ft_strncmp("rra\0", inst, 3))
		return (rra(stack_a), 0);
	else if (!ft_strncmp("rrb\0", inst, 3))
		return (rrb(stack_b), 0);
	else if (!ft_strncmp("rrr\0", inst, 3))
		return (rrr(stack_a, stack_b), 0);
	return (1);
}

int	read_instructions(t_push_list **stack_a, t_push_list **stack_b)
{
	char		*line;
	int			error;

	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		error = execute_instruction(stack_a, stack_b, line);
		free(line);
		if (error)
			return (1);
		line = get_next_line(0);
	}
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
		return (you_died(NULL, NULL, NULL, "Error\n"));
	i = 0;
	ft_lstadd_back_number(&stack_a, ft_atoi(arguements[i++]));
	if (!stack_a)
		return (you_died(NULL, NULL, NULL, "Error\n"));
	while (arguements[i])
		ft_lstadd_back_number(&stack_a, ft_atoi(arguements[i++]));
	if (repeatitions(stack_a))
		return (you_died(&stack_a, &stack_b, arguements, "Error\n"));
	if (read_instructions(&stack_a, &stack_b))
		return (you_lived(&stack_a, &stack_b, arguements, "KO\n"));
	if (is_sorted(stack_a) && i == stck_len(stack_a))
		return (you_lived(&stack_a, &stack_b, arguements, "OK\n"));
	return (you_lived(&stack_a, &stack_b, arguements, "KO\n"));
}
