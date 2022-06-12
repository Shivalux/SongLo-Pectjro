/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:54:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:07:45 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_len(char c, int len, t_flag fl)
{
	if (fl.pwi > 0)
		len = ft_printflags(' ', len, (fl.pwi - 1));
	write(1, &c, 1);
	len++;
	if (fl.mi == 1)
	{
		len = ft_printflags(' ', len, (fl.wi - 1));
	}
	return (len);
}

int	ft_printflags(char c, int len, int wi)
{
	while (wi > 0)
	{
		write(1, &c, 1);
		wi--;
		len++;
	}
	return (len);
}

int	ft_putstr_len(char *str, int len, t_flag fl)
{
	int	index;
	int	slen;

	index = 0;
	if (str == NULL)
	{
		len = ft_putstr_len("(null)", len, fl);
		return (len);
	}
	slen = ft_nstrlen(str, 1, 1);
	if (fl.dt >= 0)
		slen = ft_nstrlen(str, fl.dt, 2);
	while (index < slen && str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
		len++;
	}
	return (len);
}

int	ft_putnbr(long int nbr, char *base, int len, t_flag fl)
{
	if (nbr < 0 && ft_nstrlen(base, 1, 1) == 10)
	{
		len = ft_putchar_len('-', len, ft_setflags());
		nbr = nbr * -1;
	}
	if (nbr >= ft_nstrlen(base, 1, 1))
	{
		len = ft_putnbr(nbr / ft_nstrlen(base, 1, 1), base, len, fl);
		nbr = nbr % ft_nstrlen(base, 1, 1);
	}
	len = ft_putchar_len(base[nbr], len, ft_setflags());
	return (len);
}

int	ft_putadd(unsigned long int nbr, int len, int mode, t_flag fl)
{
	unsigned long int	rbn;
	char				*base;

	rbn = nbr;
	base = "0123456789abcdef";
	if (fl.pwi >= 0 && mode == 1)
		len = ft_printflags(' ', len, fl.pwi - ft_countul(nbr, 16) - 2);
	if (mode == 1)
		len = ft_putstr_len("0x", len, ft_setflags());
	if (nbr < 0 && ft_nstrlen(base, 1, 1) == 10)
	{
		len = ft_putchar_len('-', len, ft_setflags());
		nbr *= -1;
	}
	if (nbr >= ft_nstrlen(base, 1, 1))
	{
		len = ft_putadd(nbr / ft_nstrlen(base, 1, 1), len, 0, fl);
		nbr = nbr % ft_nstrlen(base, 1, 1);
	}
	len = ft_putchar_len(base[nbr], len, ft_setflags());
	if (mode == 1 && fl.mi == 1)
		len = ft_printflags(' ', len, (fl.wi - (ft_countul(rbn, 16) + 2)));
	return (len);
}
