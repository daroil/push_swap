/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:16:52 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/28 05:35:41 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_push_swap
{
	int					number;
	struct s_push_swap	*next;
	int					pos_a;
	int					pos_b;
	int					steps;
}					t_push_list;

void		swap(t_push_list **stack);
void		sa(t_push_list **stack);
void		sb(t_push_list **stack);
void		ss(t_push_list **stack_a, t_push_list **stack_b);
void		ra(t_push_list **stack);
void		rb(t_push_list **stack);
void		rr(t_push_list **stack_a, t_push_list **stack_b);
void		rotate(t_push_list **stack);
void		rev_rotate(t_push_list **stack);
void		rra(t_push_list **stack);
void		rrb(t_push_list **stack);
void		rrr(t_push_list **stack_a, t_push_list **stack_b);
void		push(t_push_list **source, t_push_list **dest);
void		pb(t_push_list **stack_a, t_push_list **stack_b);
void		pa(t_push_list **stack_a, t_push_list **stack_b);
void		*ft_split_clear(char **res);
char		**ft_split(char const *s, char c);
int			is_sorted(t_push_list *stack);
int			inside_array(int *array, int number, int size);
int			repeatitions(t_push_list	*stack_a);
int			all_digits(char **argv);
void		free_split(char **splitted);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			check_int(char *str);
int			all_int(char **result);
void		ft_push_clear(t_push_list **lst);
t_push_list	*get_last(t_push_list *stack);
int			stck_size(t_push_list *stack);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
t_push_list	*ft_lstlast_push(t_push_list *lst);
t_push_list	*ft_lst_second_to_last_push(t_push_list *lst);
void		ft_lstadd_number(t_push_list **lst, int number);
void		ft_lstadd_back_number(t_push_list **lst, int number);
void		ft_lstdelone_push(t_push_list *lst);
int			ft_atoi(const char *str);
int			stck_len(t_push_list *stack);
char		*get_next_line(int fd);
char		*read_to_buf(int fd, char *buf);
int			found_nl(char *buf);
char		*buf_join(char *buf, char *tmp);
size_t		gn_strlen(const char *s);
char		*gn_set_buf(char *buf);
void		gn_free_buf(char **buf);
char		*extract_line(char *buf);
char		*shorten_buf(char *buf);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			you_lived(t_push_list **stack_a, t_push_list **stack_b,
				char **args, char *exit_message);
int			you_died(t_push_list **stack_a, t_push_list **stack_b,
				char **args, char *exit_message);

#endif