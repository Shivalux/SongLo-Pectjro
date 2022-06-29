/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_situation1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:21:05 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 00:21:15 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_ending_screen(t_data *data, int f)
{
	mlx_put_image_to_window(data->mlx, data->window, \
		data->s[0].img, data->y * 32, data->x * 32);
	if (data->end == 1)
	{
		sl_ending_one(data, f);
	}
	else if (data->end == 2)
	{
		sl_ending_two(data);
	}
	else if (data->end == 3 && data->wk <= 5 \
		&& data->u[data->x][data->y].mv == 4)
	{
		sl_ending_three_one(data);
	}
	else if (data->end == 3 && data->wk <= 5 \
		&& data->u[data->x][data->y].mv != 4)
	{
		sl_ending_three_two(data);
	}
}

void	sl_ending_one(t_data *data, int f)
{
	mlx_put_image_to_window(data->mlx, data->window, data->e[5].img, \
		data->y * 32, data->x * 32);
	if (data->wk <= 5)
		sl_walking_animate(data);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->p[40 + \
			(f % 5)].img, data->y * 32, data->x * 32);
	if (data->wk == 5)
		data->map[data->x][data->y] = '0';
}

void	sl_ending_two(t_data *data)
{
	if (data->wk == 1)
	{
		sl_walking_animate(data);
		sl_patroling_animate(data, data->x, data->y, 2);
	}
	if (data->wk > 1)
	{
		sl_ending_two_player(data);
	}
	if (data->wk <= 2 && data->wk != 1)
	{
		sl_ending_two_monster(data);
	}
	else
		sl_patroling_animate(data, data->x, data->y, 2);
	if (data->wk == 5)
		data->map[data->x][data->y] = '0';
}

void	sl_ending_two_player(t_data *data)
{
	if (data->key == KEY_A)
		mlx_put_image_to_window(data->mlx, data->window, data->p[29 + data->wk \
			].img, ((data->y + 1) * 32) - (6 * 2), data->x * 32);
	else if (data->key == KEY_S)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(29 + (data-> \
			pf / 2)) + data->wk].img, data->y * 32, \
			((data->x - 1) * 32) + (6 * 2));
	else if (data->key == KEY_D)
		mlx_put_image_to_window(data->mlx, data->window, data->p[29 + data-> \
			wk].img, ((data->y - 1) * 32) + (6 * 2), data->x * 32);
	else if (data->key == KEY_W)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(29 + \
			(data-> pf / 2)) + data->wk].img, data->y * 32, \
			((data->x + 1) * 32) - (6 * 2));
}

void	sl_ending_two_monster(t_data *data)
{
	if (data->u[data->x][data->y].mv == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->m[28 + data-> \
			wk].img, (data->y * 32) - 12, data->x * 32);
	else if (data->u[data->x][data->y].mv == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->m[(28 + (data-> \
			u[data->x + 1][data->y].pf / 2)) + data->wk].img, data->y * 32, \
			(data->x * 32) + 12);
	else if (data->u[data->x][data->y].mv == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->m[28 + data-> \
		wk].img, (data->y * 32) + 12, data->x * 32);
	else if (data->u[data->x][data->y].mv == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->m[(28 + (data-> \
			u[data->x - 1][data->y].pf / 2)) + data->wk].img, data->y * 32, \
			(data->x * 32) - 12);
}
