/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:54:14 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:08:35 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_nstrlen(const char *str, int dt, int mode)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (0);
	if (mode == 1)
	{
		while (str[count] != '\0')
			count++;
		return (count);
	}
	while (count < dt && str[count] != '\0')
		count++;
	return (count);
}

int	ft_count(long int nbr, int base)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		digit++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		digit++;
		nbr /= base;
	}
	return (digit);
}

int	ft_countul(unsigned long int nbr, int base)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		digit++;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		digit++;
		nbr /= base;
	}
	return (digit);
}

void	ft_bbzero(void *s, size_t n)
{
	size_t	index;
	char	*ns;

	index = 0;
	ns = s;
	while (index < n)
	{
		ns[index] = 0;
		index++;
	}
}
