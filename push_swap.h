/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:20 by dhendzel          #+#    #+#             */
/*   Updated: 2023/02/02 14:37:44 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int					number;
	struct s_push_swap	*next;
	int					pos_a;
	int					pos_b;
	int					steps;
}					t_push_list;

void		*ft_split_clear(char **res);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
void		rrr(t_push_list **stack_a, t_push_list **stack_b);
void		rrb(t_push_list **stack);
void		rra(t_push_list **stack);
void		rr(t_push_list **stack_a, t_push_list **stack_b);
void		rb(t_push_list **stack);
void		ra(t_push_list **stack);
void		pb(t_push_list **stack_a, t_push_list **stack_b);
void		pa(t_push_list **stack_a, t_push_list **stack_b);
void		ss(t_push_list **stack_a, t_push_list **stack_b);
void		sb(t_push_list **stack);
void		sa(t_push_list **stack);
void		rotate(t_push_list **stack);
void		rev_rotate(t_push_list **stack);
void		push(t_push_list **source, t_push_list **dest);
void		swap(t_push_list **stack);
int			stck_len(t_push_list *stack);
int			*find_min_med_max(t_push_list *temp);
int			get_median(t_push_list *stack);
void		sort_int_tab(int *tab, int size);
t_push_list	*ft_lstlast_push(t_push_list *lst);
t_push_list	*ft_lst_second_to_last_push(t_push_list *lst);
void		ft_lstadd_number(t_push_list **lst, int number);
void		ft_lstadd_back_number(t_push_list **lst, int number);
void		ft_lstdelone_push(t_push_list *lst);
void		swap(t_push_list **stack);
int			stck_size(t_push_list *stack);
int			max(int a, int b);
int			min(int a, int b);
int			count_steps(int cur_pos_b, int cur_pos_a,
				t_push_list *stack_b, t_push_list *stack_a);
void		set_pos_count_steps(t_push_list *stack_b, t_push_list *stack_a,
				int cur_pos_a, int cur_pos_b);
void		steps(t_push_list *stack_a, t_push_list *head_b);
int			check_int(char *str);
int			all_int(char **result);
t_push_list	*get_last(t_push_list *stack);
int			is_sorted(t_push_list *stack);
int			inside_array(int *array, int number, int size);
int			repeatitions(t_push_list	*stack_a);
int			all_digits(char **argv);
void		ft_push_clear(t_push_list **lst);
void		push_most_to_b(t_push_list **stack_a, t_push_list **stack_b);
void		initial_swap(t_push_list **head_a);
int			stck_len(t_push_list *stack);
int			find_min_steps(t_push_list *stack);
void		push_best_b_to_a(t_push_list **stack_a, t_push_list **stack_b,
				t_push_list *a, t_push_list *b);
void		b_is_bigger(t_push_list *a, t_push_list *b, t_push_list **head_a,
				t_push_list **head_b);
void		a_is_bigger(t_push_list *b, t_push_list **head_a,
				t_push_list **head_b);
void		rev_rotate_then_push(t_push_list *a, t_push_list *b,
				t_push_list **head_a, t_push_list **head_b);
void		rotate_then_push(t_push_list *b, t_push_list **head_a,
				t_push_list **head_b);
void		pos_a(t_push_list *b, t_push_list **head_a, t_push_list **head_b);
void		pos_b(t_push_list *b, t_push_list **head_a, t_push_list **head_b);
void		rot_b_rr_a(t_push_list *a, t_push_list *b,
				t_push_list **head_a, t_push_list **head_b);
void		rrb_ra(t_push_list *b, t_push_list **head_a, t_push_list **head_b);
int			find_index_of_min(t_push_list *stack);
void		final_rotate(t_push_list **stack_a);
void		free_split(char **splitted);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_max(t_push_list *s);
int			ft_min(t_push_list *s);
void		ft_sort_3_element(t_push_list **stack_a);
void		ft_sort_5_element(t_push_list **stack_a, t_push_list **stack_b);
int			choose_and_sort(int i, t_push_list **stack_a,
				t_push_list **stack_b);
void		sort(t_push_list **head_a, t_push_list **head_b);
#endif