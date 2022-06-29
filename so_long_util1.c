/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:04:33 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:05:26 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	/* counting function*/
		/* mode1 = count 2D malloc | mode2 = count lenght of a string |
		 mode3 = count until find newline in a string */
int	sl_checklen(char **rts, char *str, int mode)
{
	int	count;

	count = 0;
	if (mode == 1 && rts != NULL)
	{
		while (rts[count] != NULL)
			count++;
		return (count);
	}
	else if (mode == 2 && str != NULL)
	{
		while (str[count] != '\0')
			count++;
		return (count);
	}
	else if (mode == 3 && str != NULL)
	{
		while (str[count] != '\n' && str[count] != '\0')
			count++;
		return (count);
	}
	return (-1);
}

	/* tools function for char ** */
		/* mode1 = print value char ** | mode0 = free char ** */
void	sl_twostars_tools(char **str, int mode)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		return ;
	}
	else if (mode == 1)
	{
		while (str[count] != NULL)
			ft_printf("%s\n", str[count++]);
		ft_printf("\n");
		return ;
	}
	else if (mode == 0)
	{
		while (str[count] != NULL)
			free(str[count++]);
		free(str);
		return ;
	}
}

	/* function finding a charactor in a string */
		/* mode1 = finding in 2 stars || mode2 = finding in 1 stars */
int	sl_checkcompair(char **rts, char *str, char c, int mode)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if ((rts == NULL && mode == 1) || (str == NULL && mode == 2))
		return (0);
	if (mode == 1)
	{
		while (rts[i] != NULL)
		{
			count += sl_checkcompair(NULL, rts[i], c, 2);
			i++;
		}
	}
	if (mode == 2)
	{
		while (str[i] != '\0')
		{	
			if (str[i] == c)
				count += 1;
			i++;
		}
	}
	return (count);
}

int	sl_count_digit(int nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}
