/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:20 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 00:56:44 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_push_swap
{
	int					number;
	struct s_push_swap	*next;
	int					pos_a;
	int					pos_b;
	int					steps;
}					push_list;

void	*ft_split_clear(char **res);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	rrr(push_list **stack_a, push_list **stack_b);
void	rrb(push_list **stack);
void	rra(push_list **stack);
void	rr(push_list **stack_a, push_list **stack_b);
void	rb(push_list **stack);
void	ra(push_list **stack);
void	pb(push_list **stack_a, push_list **stack_b);
void	pa(push_list **stack_a, push_list **stack_b);
void	ss(push_list **stack_a, push_list **stack_b);
void	sb(push_list **stack);
void	sa(push_list **stack);
void	rotate(push_list **stack);
void	rev_rotate(push_list **stack);
void	push(push_list **source, push_list **dest);
void	swap(push_list **stack);
int	stck_len(push_list *stack);
int	*find_min_med_max(push_list *temp);
int	get_median(push_list *stack);
void	sort_int_tab(int *tab, int size);
push_list	*ft_lstlast_push(push_list *lst);
push_list	*ft_lst_second_to_last_push(push_list *lst);
void	ft_lstadd_number(push_list **lst, int number);
void	ft_lstadd_back_number(push_list **lst, int number);
void	ft_lstdelone_push(push_list *lst);
void	swap(push_list **stack);
int	stck_size(push_list *stack);
int	max(int a, int b);
int	min(int a, int b);
int	count_steps(int cur_pos_b, int cur_pos_a,
	push_list *stack_b, push_list *stack_a);
void	set_pos_count_steps(push_list *stack_b, push_list *stack_a,
	int cur_pos_a, int cur_pos_b);
void	steps(push_list *stack_a, push_list *head_b);
int	check_int(char *str);
int	all_int(char **result);
push_list	*get_last(push_list *stack);
int	is_sorted(push_list *stack);
int	inside_array(int *array, int number, int size);
int	repeatitions(push_list	*stack_a);
int	all_digits(char **argv);
void	ft_push_clear(push_list **lst);
void	push_most_to_b(push_list **stack_a, push_list **stack_b);
void	initial_swap(push_list **head_a);
int	stck_len(push_list *stack);
int	find_min_steps(push_list *stack);
void	push_best_b_to_a(push_list **stack_a, push_list **stack_b, push_list *a, push_list *b);
void	b_is_bigger(push_list *a, push_list *b, push_list **head_a, push_list **head_b);
void	a_is_bigger(push_list *b, push_list **head_a, push_list **head_b);
void	rev_rotate_then_push(push_list *a, push_list *b, push_list **head_a, push_list **head_b);
void	rotate_then_push(push_list *b, push_list **head_a, push_list **head_b);
void	pos_a(push_list *b, push_list **head_a, push_list **head_b);
void	pos_b(push_list *b, push_list **head_a, push_list **head_b);
void	rot_b_rr_a(push_list *a, push_list *b, push_list **head_a, push_list **head_b);
void	rrb_ra(push_list *b, push_list **head_a, push_list **head_b);
int	find_index_of_min(push_list *stack);
void	final_rotate(push_list **stack_a);
void	free_split(char **splitted);

#endif