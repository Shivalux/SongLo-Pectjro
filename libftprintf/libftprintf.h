/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:08:51 by sharnvon          #+#    #+#             */
/*   Updated: 2022/04/30 02:08:56 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int	mi;
	int	sp;
	int	ze;
	int	pl;
	int	sh;
	int	dt;
	int	wi;
	int	pwi;
}	t_flag;

void			*ft_ncalloc(size_t count, size_t size);
void			ft_bbzero(void *s, size_t n);
int				ft_atoip(const char *str);
int				ft_count_flag_i(const char *format,
					int i, char *str, int mode);
int				ft_count(long int nbr, int base);
int				ft_countul(unsigned long int nbr, int base);
int				ft_checkdot(const char *format, int i);
int				ft_checkpwinbr(long int nbr, int len, char *base, t_flag fl);
int				ft_checkflagnbr(long int nbr, int len, char *base, t_flag fl);
int				ft_putchar_len(char c, int len, t_flag fl);
int				ft_putstr_len(char *str, int len, t_flag fl);
int				ft_putnbr(long int nbr, char *base, int len, t_flag fl);
int				ft_putadd(unsigned long int nbr, int len, int mode, t_flag fl);
int				ft_prenbr(long int nbr, char *base, int len, t_flag fl);
int				ft_prestr(char *str, int len, t_flag fl);
int				ft_printf(const char *format, ...);
int				ft_printflags(char c, int len, int wi);
int				ft_print_args(const char *format, int i,
					int len, va_list arg);
int				ft_strcmp(char c, char *str);
unsigned int	ft_nstrlen(const char *str, int dt, int mode);
t_flag			ft_checkflag(const char *format, int i, t_flag fl);
t_flag			ft_setflags(void);
t_flag			ft_precheckflag(const char *format, int i, t_flag fl);

#endif
