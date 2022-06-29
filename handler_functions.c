/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:10:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 00:10:50 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_keyinput(int keycode, t_data *data)
{
	if (keycode == KEY_A && data->y > 0 && data->wk > 5 && data->end == 0 && \
		data->map[data->x][data->y - 1] != 'E' && data->map[data->x][data->y \
		- 1] != '1')
		sl_key_manage(data, keycode);
	else if (keycode == KEY_S && data->x < sl_checklen(data->map, NULL, 1) - 1 \
		&& data->wk > 5 && data->end == 0 && data->map[data->x + 1][data->y] \
		!='E' && data->map[data->x + 1][data->y] != '1')
		sl_key_manage(data, keycode);
	else if (keycode == KEY_D && data->y < sl_checklen(NULL, data->map[0], 2) \
		- 1 && data->wk > 5 && data->end == 0 && data->map[data->x][data->y + \
		1] != 'E' && data->map[data->x][data->y + 1] != '1')
		sl_key_manage(data, keycode);
	else if (keycode == KEY_W && data->x > 0 && data->wk > 5 && data->end == 0 \
	&& data->map[data->x - 1][data->y] != 'E' && data->map[data->x - 1] \
	[data->y] != '1')
		sl_key_manage(data, keycode);
	else if (keycode == KEY_ESC)
	{
		sl_free_for_all(data, 2);
	}
	return (0);
}

void	sl_key_manage(t_data *d, int k)
{
	if (k == 0 && sl_checkcompair(0, "1E", d->map[d->x][d->y - 1], 2) == 0)
	{
		d->mc += sl_walkswap(d, KEY_A);
		sl_mon_patrolswap(d, 0, 1, 'Z');
		d->pf = 10;
	}
	if (k == 1 && sl_checkcompair(0, "1E", d->map[d->x + 1][d->y], 2) == 0)
	{
		d->mc += sl_walkswap(d, KEY_S);
		sl_mon_patrolswap(d, 0, 1, 'Z');
	}
	if (k == 2 && sl_checkcompair(0, "1E", d->map[d->x][d->y + 1], 2) == 0)
	{
		d->mc += sl_walkswap(d, KEY_D);
		sl_mon_patrolswap(d, 0, 1, 'Z');
		d->pf = 0;
	}
	if (k == 13 && sl_checkcompair(0, "1E", d->map[d->x - 1][d->y], 2) == 0)
	{
		d->mc += sl_walkswap(d, KEY_W);
		sl_mon_patrolswap(d, 0, 1, 'Z');
	}
	ft_printf("movement count == %d\n", d->mc);
}

int	sl_close(t_data *data)
{
	sl_free_for_all(data, 2);
	exit(0);
}

int	sl_animating(t_data *data)
{
	static int	count = 0;

	if (count >= 7999)
		count = 0;
	if (count % 800 == 0)
	{
		sl_map_generate(data, count / 800);
	}
	count = count + 1;
	return (0);
}
