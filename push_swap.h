/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:51:20 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 22:47:31 by dhendzel         ###   ########.fr       */
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

#endif