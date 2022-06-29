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

int	ft_count_flag_i(const char *format, int i, char *str, int mode)
{
	int		count;
	char	*number;

	count = 0;
	if (mode == 1)
	{
		while (ft_strcmp(format[i + count], "0123456789") == 1)
			count++;
		number = (char *)calloc(sizeof(char), count + 1);
		if (number == NULL)
			return (0);
		count = 0;
		while (ft_strcmp(format[i + count], "0123456789") == 1)
		{
			number[count] = format[i + count];
			count++;
		}
		count = ft_atoip(number);
		free(number);
		return (count);
	}
	while (ft_strcmp(format[i], str) == 0)
		i++;
	return (i);
}

t_flag	ft_checkflag(const char *format, int i, t_flag fl)
{
	if (format[i] == '-')
		fl.mi = 1;
	if (format[i] == ' ')
		fl.sp = 1;
	if (format[i] == '0')
		fl.ze = 1;
	if (format[i] == '+')
		fl.pl = 1;
	if (format[i] == '#')
		fl.sh = 1;
	if (format[i] == '.')
		fl.dt = ft_count_flag_i(format, i + 1, "0", 1);
	return (fl);
}

t_flag	ft_precheckflag(const char *format, int i, t_flag fl)
{
	if (ft_strcmp(format[i], "123456789") == 1
		|| (format[i] == '0' && ft_checkdot(format, i) == 1))
	{
		fl.pwi = ft_count_flag_i(format, i, "0", 1);
		i = ft_count_flag_i(format, i, "- +#.cspdiuxX%", 2);
	}
	while (ft_strcmp(format[i], "- 0+#.") == 1)
	{
		fl = ft_checkflag(format, i, fl);
		i++;
		if (ft_strcmp(format[i], "0123456789") == 1 && fl.wi < 0)
		{
			fl.wi = ft_count_flag_i(format, i, "0", 1);
			i = ft_count_flag_i(format, i, "- +#.cspdiuxX%", 2);
		}
	}
	return (fl);
}

int	ft_print_args(const char *format, int i, int len, va_list arg)
{
	t_flag	fl;

	fl = ft_setflags();
	fl = ft_precheckflag(format, i, fl);
	i = ft_count_flag_i(format, i, "cspdiuxX%", 2);
	if (format[i] == 'c')
		len = ft_putchar_len(va_arg(arg, int), len, fl);
	if (format[i] == 's')
		len = ft_prestr(va_arg(arg, char *), len, fl);
	if (format[i] == 'd' || format[i] == 'i')
		len = ft_prenbr(va_arg(arg, int), "0123456789", len, fl);
	if (format[i] == 'u')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789", len, fl);
	if (format[i] == 'x')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789abcdef", len, fl);
	if (format[i] == 'X')
		len = ft_prenbr(va_arg(arg, unsigned int), "0123456789ABCDEF", len, fl);
	if (format[i] == 'p')
		len = ft_putadd(va_arg(arg, long int), len, 1, fl);
	if (format[i] == '%')
		len = ft_putchar_len('%', len, ft_setflags());
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		format_len;
	va_list	arg;
	int		len;

	i = 0;
	len = 0;
	format_len = ft_nstrlen(format, 1, 1);
	va_start(arg, format);
	while (i < format_len)
	{
		if (format[i] == '%')
		{
			i++;
			len = ft_print_args(format, i, len, arg);
			i = ft_count_flag_i(format, i, "cspdiuxX%", 2);
		}
		else
			len = ft_putchar_len(format[i], len, ft_setflags());
		i++;
	}
	va_end(arg);
	return (len);
}
