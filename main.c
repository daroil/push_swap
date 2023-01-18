/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:49:12 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/18 13:59:42 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("i:%d arguement:%s\n",i,argv[i]);
		i++;
	}
	return (0);
}