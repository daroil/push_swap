/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:18 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:32:19 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pc(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		pc(s[i]);
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

void	free_list(t_list *head)
{
	t_list	*temp;

	if (head)
	{
		temp = head->next;
		free(head);
		free_list(temp);
	}
}
