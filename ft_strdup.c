/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:51:14 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/27 16:26:05 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}	
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s_dup;

	len = ft_strlen (s1);
	s_dup = malloc (len + 1);
	if (!s_dup)
		return (NULL);
	ft_strlcpy (s_dup, s1, len + 1);
	return (s_dup);
}
