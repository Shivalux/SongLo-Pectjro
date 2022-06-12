/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:53:29 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:06:43 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_count_flag_index(const char *format, int index, char *str, int mode)
{
	int		count;
	char	*number;

	count = 0;
	if (mode == 1)
	{
		while (ft_strcmp(format[index + count], "0123456789") == 1)
			count++;
		number = (char *)calloc(sizeof(char), count + 1);
		if (number == NULL)
			return (0);
		count = 0;
		while (ft_strcmp(format[index + count], "0123456789") == 1)
		{
			number[count] = format[index + count];
			count++;
		}
		count = ft_atoip(number);
		free(number);
		return (count);
	}
	while (ft_strcmp(format[index], str) == 0)
		index++;
	return (index);
}

t_flag	ft_checkflag(const char *format, int index, t_flag fl)
{
	if (format[index] == '-')
		fl.mi = 1;
	if (format[index] == ' ')
		fl.sp = 1;
	if (format[index] == '0')
		fl.ze = 1;
	if (format[index] == '+')
		fl.pl = 1;
	if (format[index] == '#')
		fl.sh = 1;
	if (format[index] == '.')
		fl.dt = ft_count_flag_index(format, index + 1, "0", 1);
	return (fl);
}

t_flag	ft_precheckflag(const char *format, int index, t_flag fl)
{
	if (ft_strcmp(format[index], "123456789") == 1
		|| (format[index] == '0' && ft_checkdot(format, index) == 1))
	{
		fl.pwi = ft_count_flag_index(format, index, "0", 1);
		index = ft_count_flag_index(format, index, "- +#.cspdiuxX%", 2);
	}
	while (ft_strcmp(format[index], "- 0+#.") == 1)
	{
		fl = ft_checkflag(format, index, fl);
		index++;
		if (ft_strcmp(format[index], "0123456789") == 1 && fl.wi < 0)
		{
			fl.wi = ft_count_flag_index(format, index, "0", 1);
			index = ft_count_flag_index(format, index, "- +#.cspdiuxX%", 2);
		}
	}
	return (fl);
}

int	ft_print_args(const char *format, int index, int len, va_list arg)
{
	t_flag	fl;

	fl = ft_setflags();
	fl = ft_precheckflag(format, index, fl);
	index = ft_count_flag_index(format, index, "cspdiuxX%", 2);
	if (format[index] == 'c')
		len = ft_putchar_len(va_arg(arg, int), len, fl);
	if (format[index] == 's')
		len = ft_prestr(va_arg(arg, char *), len, fl);
	if (format[index] == 'd' || format[index] == 'i')
		len = ft_prenbr(va_arg(arg, int), "0123456789", len, fl);
	if (format[index] == 'u')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789", len, fl);
	if (format[index] == 'x')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789abcdef", len, fl);
	if (format[index] == 'X')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789ABCDEF", len, fl);
	if (format[index] == 'p')
		len = ft_putadd(va_arg(arg, long int), len, 1, fl);
	if (format[index] == '%')
		len = ft_putchar_len('%', len, ft_setflags());
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		format_len;
	va_list	arg;
	int		len;

	index = 0;
	len = 0;
	format_len = ft_nstrlen(format, 1, 1);
	va_start(arg, format);
	while (index < format_len)
	{
		if (format[index] == '%')
		{
			index++;
			len = ft_print_args(format, index, len, arg);
			index = ft_count_flag_index(format, index, "cspdiuxX%", 2);
		}
		else
			len = ft_putchar_len(format[index], len, ft_setflags());
		index++;
	}
	va_end(arg);
	return (len);
}
