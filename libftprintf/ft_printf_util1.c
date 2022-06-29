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
	int	i_c;
	int	minus;
	int	result;

	result = 0;
	minus = 1;
	i_c = 0;
	while ((str[i_c] >= 9 && str[i_c] <= 13) || str[i_c] == ' ')
	{
		i_c++;
	}
	if (str[i_c] == '+' || str[i_c] == '-')
	{
		if (str[i_c] == '-')
		{
			minus = minus * -1;
		}
		i_c++;
	}
	while (str[i_c] != '\0' && str[i_c] >= '0' && str[i_c] <= '9')
	{
		result = result * 10 + (str[i_c] - '0');
		i_c++;
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
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkdot(const char *format, int i)
{
	while (ft_strcmp(format[i], "csdiuxXp%") == 0)
	{
		if (format[i] == '.')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
