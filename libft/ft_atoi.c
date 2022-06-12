/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:32:03 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/19 16:26:31 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index_c;
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	index_c = 0;
	while ((str[index_c] >= 9 && str[index_c] <= 13) || str[index_c] == ' ')
	{
		index_c++;
	}
	if (str[index_c] == '+' || str[index_c] == '-')
	{
		if (str[index_c] == '-')
		{
			minus = minus * -1;
		}
		index_c++;
	}
	while (str[index_c] != '\0' && str[index_c] >= '0' && str[index_c] <= '9')
	{
		result = result * 10 + (str[index_c] - '0');
		index_c++;
	}
	return (result * minus);
}
