/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:31:33 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/25 18:31:35 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_znak(int n)
{
	int	znak;

	znak = 1;
	if (n < 0)
		znak = -1;
	return (znak);
}

char	*ft_nul(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		znak;

	znak = ft_znak(n);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	ft_nul(n, str);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) * ((2 * (n > 0)) - 1) + '0');
		n = n / 10;
	}
	len--;
	if (znak < 0)
		str[len] = '-';
	return (str);
}
