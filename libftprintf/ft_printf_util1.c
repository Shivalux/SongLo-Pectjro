/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:53:53 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:08:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_atoip(const char *str)
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

void	*ft_ncalloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
	{
		return (0);
	}
	ft_bbzero (str, (size * count));
	return (str);
}

t_flag	ft_setflags(void)
{
	t_flag	fl;

	fl.mi = -1;
	fl.sp = -1;
	fl.ze = -1;
	fl.pl = -1;
	fl.sh = -1;
	fl.dt = -1;
	fl.wi = -1;
	fl.pwi = -1;
	return (fl);
}

int	ft_strcmp(char c, char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int	ft_checkdot(const char *format, int index)
{
	while (ft_strcmp(format[index], "csdiuxXp%") == 0)
	{
		if (format[index] == '.')
		{
			return (1);
		}
		index++;
	}
	return (0);
}
