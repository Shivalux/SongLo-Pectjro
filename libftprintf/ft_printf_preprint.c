/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_preprint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:54:36 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:07:09 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_prestr(char *str, int len, t_flag fl)
{
	int	slen;

	if (str != NULL)
		slen = ft_nstrlen(str, 1, 1);
	if (fl.sp == 1 && fl.wi > 0)
	{
		len = ft_printflags(' ', len, (fl.wi - ft_nstrlen(str, 1, 1)));
		if (str == NULL)
			len = ft_printflags(' ', len, (fl.wi - 6));
		fl.wi = 0;
	}
	if (fl.pwi > 0)
	{
		if (str != NULL)
			len = ft_printflags(' ', len, fl.pwi - ft_nstrlen(str, 1, 1));
		else if (str == NULL)
			len = ft_printflags(' ', len, (fl.pwi - 6));
	}
	len = ft_putstr_len(str, len, fl);
	if (fl.dt > 0)
		slen = ft_nstrlen(str, fl.dt, 2);
	if ((fl.wi > 0 && fl.dt == 0) || fl.mi == 1)
		len = ft_printflags(' ', len, fl.wi - slen);
	return (len);
}

int	ft_checkflagnbr(long int nbr, int len, char *base, t_flag fl)
{
	if (fl.pl == 1 && nbr > -1 && ft_nstrlen(base, 1, 1) == 10)
		len = ft_putchar_len('+', len, fl);
	if (fl.sh == 1 && nbr && base[10] == 'a')
		len = ft_putstr_len("0x", len, ft_setflags());
	if (fl.sh == 1 && nbr && base[10] == 'A')
		len = ft_putstr_len("0X", len, ft_setflags());
	if (fl.sp == 1 && ft_nstrlen(base, 1, 1) == 10 && fl.wi < 0 && nbr > -1)
		len = ft_putchar_len(' ', len, fl);
	if (fl.sp == 1 && ft_nstrlen(base, 1, 1) == 10 && fl.wi >= 0)
		len = ft_printflags(' ', len, (fl.wi - ft_count(nbr, 10)));
	if (fl.ze == 1 || fl.dt >= 0)
	{
		if (nbr < 0)
			len = ft_putchar_len('-', len, ft_setflags());
		if (fl.dt >= 0 && fl.dt >= ft_count(nbr, ft_nstrlen(base, 1, 1))
			&& ft_nstrlen(base, 1, 1) == 10 && nbr < 0)
			len = ft_putchar_len('0', len, ft_setflags());
		if (fl.ze == 1)
			len = ft_printflags('0', len,
					(fl.wi - ft_count(nbr, ft_nstrlen(base, 1, 1))));
		else
			len = ft_printflags('0', len,
					(fl.dt - ft_count(nbr, ft_nstrlen(base, 1, 1))));
	}
	return (len);
}

int	ft_checkpwinbr(long int nbr, int len, char *base, t_flag fl)
{
	if (fl.dt >= 0 && fl.dt > ft_count(nbr, ft_nstrlen(base, 1, 1)) && nbr < 0)
		len = ft_printflags(' ', len, fl.pwi - (fl.dt + 1));
	else if (fl.dt >= 0 && fl.dt > ft_count(nbr, ft_nstrlen(base, 1, 1)))
		len = ft_printflags(' ', len, fl.pwi - fl.dt);
	else
	{	
		if (nbr == 0 && fl.dt == 0)
			len = ft_printflags(' ', len,
					1 + fl.pwi - ft_count(nbr, ft_nstrlen(base, 1, 1)));
		else
			len = ft_printflags(' ', len,
					fl.pwi - ft_count(nbr, ft_nstrlen(base, 1, 1)));
	}
	return (len);
}

int	ft_prenbr(long int nbr, char *base, int len, t_flag fl)
{
	if (fl.pwi >= 0)
		len = ft_checkpwinbr(nbr, len, base, fl);
	len = ft_checkflagnbr(nbr, len, base, fl);
	if ((fl.ze == 1 && nbr < 0) || (fl.dt >= 0 && nbr < 0))
	{
		nbr = nbr * -1;
		fl.wi = fl.wi - 1;
	}
	if (!(fl.dt == 0 && nbr == 0))
		len = ft_putnbr(nbr, base, len, fl);
	if (fl.mi == 1)
	{
		if ((fl.dt >= 0 && fl.dt > ft_count(nbr, ft_nstrlen(base, 1, 1)))
			|| (fl.dt >= 0 && nbr == 0))
			len = ft_printflags(' ', len, fl.wi - fl.dt);
		else
			len = ft_printflags(' ', len,
					fl.wi - (ft_count(nbr, ft_nstrlen(base, 1, 1))));
	}
	return (len);
}
