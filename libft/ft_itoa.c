/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:51:20 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 20:15:45 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len = len + 1;
	}
	while (n != 0)
	{
		len = len + 1;
		n = n / 10;
	}		
	return (len);
}

char	*ft_assigned_value(int len, int n, char *result)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[len] = '8';
			n = (n / 10);
			len = len - 1;
		}
		n = n * -1;
		result[0] = '-';
	}
	while (n != 0)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = 0;
	if (n == 0)
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (result == NULL)
			return (0);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	len = ft_count_digit(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	result[len] = '\0';
	len = len - 1;
	result = ft_assigned_value(len, n, result);
	return (result);
}
