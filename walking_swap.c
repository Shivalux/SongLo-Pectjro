/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:06:07 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:06:10 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_check_collectible(t_data *data, int key, int i)
{
	int	xedni;

	if (key == KEY_W && data->map[data->x - 1][data->y] == 'C')
		data->map[data->x - 1][data->y] = '0';
	else if (key == KEY_A && data->map[data->x][data->y - 1] == 'C')
		data->map[data->x][data->y - 1] = '0';
	else if (key == KEY_S && data->map[data->x + 1][data->y] == 'C')
		data->map[data->x + 1][data->y] = '0';
	else if (key == KEY_D && data->map[data->x][data->y + 1] == 'C')
		data->map[data->x][data->y + 1] = '0';
	if (sl_checkcompair(data->map, NULL, 'C', 1) == 0)
	{
		while (data->map[i] != NULL)
		{
			xedni = 0;
			while (data->map[i][xedni] != '\0')
			{
				if (data->map[i][xedni] == 'E')
					data->map[i][xedni] = '0';
				xedni++;
			}
			i++;
		}
	}
}

void	sl_swapvalue(t_data *data, int mode, char tmp)
{
	if (mode == KEY_W)
	{
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x - 1][data->y];
		data->map[data->x - 1][data->y] = tmp;
	}
	else if (mode == KEY_A)
	{
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y -1];
		data->map[data->x][data->y - 1] = tmp;
	}
	else if (mode == KEY_S)
	{
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x + 1][data->y];
		data->map[data->x + 1][data->y] = tmp;
	}
	else if (mode == KEY_D)
	{
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y + 1];
		data->map[data->x][data->y + 1] = tmp;
	}
	data->wk = 1;
}

int	sl_walkswap(t_data *data, int mode)
{
	char	tmp;

	tmp = '\0';
	sl_check_collectible(data, mode, 0);
	sl_swapvalue(data, mode, tmp);
	if (mode == KEY_W)
	{	
		data->key = KEY_W;
	}
	else if (mode == KEY_A)
	{
		data->key = KEY_A;
	}
	else if (mode == KEY_S)
	{
		data->key = KEY_S;
	}
	else if (mode == KEY_D)
	{
		data->key = KEY_D;
	}
	return (1);
}
