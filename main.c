/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 22:56:44 by dhendzel         ###   ########.fr       */
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
}

void	rev_rotate(push_list **stack)
{
	push_list	*first;
	push_list	*second_to_last;
	push_list	*last;
	
	if (stck_size(*stack) < 2)
		return ;
	first = *stack;
	last = ft_lstlast_push(*stack);
	second_to_last = ft_lst_second_to_last_push(*stack);
	last->next = first;
	*stack = last;
	second_to_last->next = NULL;
}

int	get_max(push_list *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->number;
	while (stack->next)
	{
		if (max < stack->number)
			max = stack->number;
		stack = stack->next;
	}
	if (max < stack->number)
			max = stack->number;
	return (max);
}

int	get_min(push_list *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->number;
	while (stack->next)
	{
		if (min > stack->number)
			min = stack->number;
		stack = stack->next;
	}
	if (min > stack->number)
			min = stack->number;
	return (min);
}

void	sort_int_tab(int *tab, int size)
{
	int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	get_median(push_list *stack)
{
	int	median;
	int	size;
	int	*array;
	int	i;

	if(!stack)
		return(0);
	i = 0;
	size = stck_size(stack);
	array = malloc(sizeof(int) * size);
	while (stack)
	{
		array[i] = stack->number;
		i++;
		stack = stack->next;
	}	
	sort_int_tab(array, size);
	median = array[i / 2];
	free(array);
	return (median);
}

// void	swapp(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// void	selection_sort(int *arr, int n)
// {
// 	int	i;
// 	int	j;
// 	int	min_idx;

// 	i = 0;
// 	while (i < n - 1)
// 	{
// 		min_idx = i;
// 		j = i + 1;
// 		while (j < n)
// 		{
// 			if (arr[j] < arr[min_idx])
// 				min_idx = j;
// 			j++;
// 		}
// 		swapp(&arr[min_idx], &arr[i]);
// 		i++;
// 	}
// }

// int	get_median(push_list *head)
// {
// 	int	*res;
// 	int	i;

// 	i = 0;
// 	res = malloc(sizeof(int) * stck_len(head));
// 	if (!res)
// 	{
// 		head->steps = -1;
// 		return (0);
// 	}
// 	while (head)
// 	{
// 		res[i] = head->number;
// 		i++;
// 		head = head->next;
// 	}
// 	selection_sort(res, i);
// 	i = res[i / 2];
// 	free(res);
// 	// printf("median  %d\n",i);
// 	return (i);
// }

int	all_digits(char **argv)
{
	int	i;
	int	j;
	int	minus;

	i = 0;
	while (argv[i])
	{
		minus = 0;
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
					minus += 1;
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				return (0);
			if (minus > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > MAX_INT || res < MIN_INT)
			return (0);
	}
	res *= sign;
	if (res > MAX_INT || res < MIN_INT)
		return (0);
	return (1);
}

int	all_int(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		if (!check_int(result[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

char	**get_args(int argc, char **argv)
{
	char	**result;
	int		i;

	i = 0;
	if (argc == 2 && !all_digits(argv + 1))
	{
		result = ft_split(argv[1], ' ');
	}
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

int	*find_min_med_max(push_list *temp)
{
	int		minim;
	int		maxim;
	int		*res;

	res = malloc(sizeof(int) * 3);
	if (!res)
		return (NULL);
	minim = MAX_INT;
	maxim = MIN_INT;
	while (temp)
	{
		if (temp->number > maxim)
			maxim = temp->number;
		if (temp->number < minim)
			minim = temp->number;
		temp = temp->next;
	}
	res[0] = minim;
	res[2] = maxim;
	res[1] = get_median(temp);
	return (res);
}

void	push_most_to_b(push_list **stack_a, push_list **stack_b)
{
	int	*min_max_med;

	min_max_med = find_min_med_max(*stack_a);
	while (stck_len(*stack_a) > 3)
	{
		if ((*stack_a)->number != min_max_med[0]
			&& (*stack_a)->number != min_max_med[1]
			&& (*stack_a)->number != min_max_med[2])
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

push_list	*get_last(push_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	initial_swap(push_list **head_a)
{
	push_list	*a;

	if (stck_size(*head_a) != 3)
		return ;
	a = *head_a;
	if ((a->number < a->next->number && a->number < a->next->next->number
			&& a->next->number > a->next->next->number)
		|| (a->number > a->next->number
			&& a->number < a->next->next->number
			&& a->next->number < a->next->next->number)
		|| (a->number > a->next->number && a->number > a->next->next->number
			&& a->next->number > a->next->next->number))
		sa(head_a);
}

int	stck_len(push_list *stack)
{
	push_list	*temp;
	int		res;

	res = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	count_steps(int cur_pos_b, int cur_pos_a,
	push_list *stack_b, push_list *stack_a)
{
	return (min(min(max(cur_pos_b, cur_pos_a),
				max(stck_len(stack_b), stck_len(stack_a))),
			min(cur_pos_b + stck_len(stack_a),
				cur_pos_a + stck_len(stack_b))) + 1);
}

void	set_pos_count_steps(push_list *stack_b, push_list *stack_a,
	int cur_pos_a, int cur_pos_b)
{
	stack_b->steps = count_steps(cur_pos_b, cur_pos_a, stack_b, stack_a);
	stack_b->pos_a = cur_pos_a;
	stack_b->pos_b = cur_pos_b;
}

void	steps(push_list *stack_a, push_list *head_b)
{
	int		cur_pos_a;
	int		cur_pos_b;
	push_list	*temp;
	
	cur_pos_b = 0;
	while (head_b)
	{
		temp = stack_a;
		if ((get_last(temp)->number < head_b->number)
			&& (temp->number > head_b->number))
			set_pos_count_steps(head_b, temp, 0, cur_pos_b);
		cur_pos_a = 1;
		while (temp->next)
		{
			if ((temp->number < head_b->number)
				&& (temp->next->number > head_b->number))
				set_pos_count_steps(head_b, temp->next, cur_pos_a, cur_pos_b);
			temp = temp->next;
			cur_pos_a++;
		}
		head_b = head_b->next;
		cur_pos_b++;
	}
}

int	find_min_steps(push_list *stack)
{
	int	min_steps;

	min_steps = MAX_INT;
	while (stack)
	{
		if (stack->steps < min_steps)
			min_steps = stack->steps;
		stack = stack->next;
	}
	return (min_steps);
}

void	pos_a(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = b->pos_a;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->pos_b - b->pos_a;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	pos_b(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = b->pos_b;
	while (iter)
	{
		rr(head_a, head_b);
		iter--;
	}
	iter = b->pos_a - b->pos_b;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	rotate_then_push(push_list *b, push_list **head_a, push_list **head_b)
{
	if (b->pos_a < b->pos_b)
		pos_a(b, head_a, head_b);
	else
		pos_b(b, head_a, head_b);
}

void	b_is_bigger(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(a) - b->pos_a;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = stck_len(*head_b) - b->pos_b
		- stck_len(*head_a) + b->pos_a;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	pa(head_a, head_b);
}

void	a_is_bigger(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(*head_b) - b->pos_b;
	while (iter)
	{
		rrr(head_a, head_b);
		iter--;
	}
	iter = stck_len(*head_a) - b->pos_a
		- stck_len(*head_b) + b->pos_b;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	rev_rotate_then_push(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	if (stck_len(a) - b->pos_a
		< stck_len(*head_b) - b->pos_b)
		b_is_bigger(a, b, head_a, head_b);
	else
		a_is_bigger(b, head_a, head_b);
}

void	rot_b_rr_a(push_list *a, push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = b->pos_b;
	while (iter)
	{
		rb(head_b);
		iter--;
	}
	iter = stck_len(a) - b->pos_a;
	while (iter)
	{
		rra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	rrb_ra(push_list *b, push_list **head_a, push_list **head_b)
{
	int	iter;

	iter = stck_len(*head_b) - b->pos_b;
	while (iter)
	{
		rrb(head_b);
		iter--;
	}
	iter = b->pos_a;
	while (iter)
	{
		ra(head_a);
		iter--;
	}
	pa(head_a, head_b);
}

void	push_best_b_to_a(push_list **stack_a, push_list **stack_b, push_list *a, push_list *b)
{
	int		min_steps;

	min_steps = find_min_steps(b);
	while (stack_a)
	{	
		if (b->steps == min_steps)
		{
			if (min_steps == max(b->pos_a, b->pos_b) + 1)
				rotate_then_push(b, stack_a, stack_b);
			else if (min_steps == max(stck_len(a)
					- b->pos_a, stck_len(*stack_b) - b->pos_b) + 1)
				rev_rotate_then_push(a, b, stack_a, stack_b);
			else if (min_steps == b->pos_b + stck_len(a) - b->pos_a + 1)
				rot_b_rr_a(a, b, stack_a, stack_b);
			else if (min_steps == b->pos_a
				+ stck_len(*stack_b) - b->pos_b + 1)
				rrb_ra(b, stack_a, stack_b);
			return ;
		}
		b = b->next;
	}
}

int	find_index_of_min(push_list *stack)
{
	int	index;
	int	i;
	int	counter;

	i = MAX_INT;
	index = 0;
	counter = 0;
	while (stack)
	{
		if (stack->number < i)
		{
			i = stack->number;
			index = counter;
		}
		counter++;
		stack = stack->next;
	}
	return (index);
}


void	final_rotate(push_list **stack_a)
{
	int		index;

	index = find_index_of_min(*stack_a);
	if (index < stck_len(*stack_a) - index)
	{
		while (index--)
			ra(stack_a);
	}
	else
	{
		index = stck_len(*stack_a) - index;
		while (index--)
			rra(stack_a);
	}
}


void	sort(push_list **head_a, push_list **head_b)
{
	push_list	*a;
	push_list	*b;

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

int main(int argc, char **argv)
{
	int	i;
	push_list	*stack_a;
	push_list	*stack_b;
	push_list	*tmp;
	push_list	*tmp_b;
	char		**args;

	args = get_args(argc, argv);
	// i = 0;
	// while (args[i])
	// {
	// 	printf("%s\n",args[i]);
	// 	i++;	
	// }
	// atexit(chckleaks);
	if (!argc)
		return (0);
	i = 0;
	while (args[i])
	{
		ft_lstadd_back_number(&stack_a, ft_atoi(args[i]));
		i++;
	}
	// i = 0;
	// tmp = stack_a;
	// while (stack_a->next)
	// {
	// 	printf("integer %d:%d \n", i, stack_a->number);
	// 	i++;
	// 	stack_a = stack_a->next;
	// }
	// printf("integer %d:%d \n", i, stack_a->number);
	// stack_a = tmp;
	// printf("max int in stack_a %d\n",get_max(stack_a));
	// printf("min int in stack_a %d\n",get_min(stack_a));
	// printf("median int in stack_a %d\n",get_median(stack_a));
	push_most_to_b(&stack_a, &stack_b);
	sort(&stack_a, &stack_b);
	// swap(&stack_a);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// rotate(&stack_a);
	// rev_rotate(&stack_a);
	// rotate(&stack_b);
	// printf("max int in stack_a %d\n",get_max(stack_a));
	// printf("min int in stack_a %d\n",get_min(stack_a));
	// printf("max int in stack_b %d\n",get_max(stack_b));
	// tmp = stack_a;
	// i = 0;
	// while (stack_a->next)
	// {
	// 	printf("integer %d:%d \n", i, stack_a->number);
	// 	i++;
	// 	stack_a = stack_a->next;
	// }
	// printf("integer %d:%d \n", i, stack_a->number);
	// i = 0;
	// tmp_b = stack_b;
	// while (stack_b->next)
	// {
	// 	printf("integer stack b %d:%d \n", i, stack_b->number);
	// 	i++;
	// 	stack_b = stack_b->next;
	// }
	// printf("integer stack b %d:%d \n", i, stack_b->number);
	ft_push_clear(&tmp);
	ft_push_clear(&tmp_b);
	free_split(args);
	return (0);
}