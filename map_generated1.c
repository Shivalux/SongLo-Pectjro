/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generated1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:51:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:51:33 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_map_generate(t_data *data, int f)
{
	mlx_clear_window(data->mlx, data->window);
	sl_putimage_space_layer(data);
	sl_putimage_map_layer(data, f);
	sl_checkending(data, 3);
	sl_putimage_monster(data, f);
	sl_checkending(data, 1);
	if ((data->wk <= 5 && data->end != 0) || data->end == 1)
		sl_ending_screen(data, f);
	sl_putimage_count(data);
	data->wk += 1;
}

void	sl_putimage_space_layer(t_data *data)
{
	int	i;
	int	xedni;

	i = 0;
	while (data->map[i] != NULL)
	{
		xedni = 0;
		while (data->map[i][xedni] != '\0')
		{
			if (data->map[i][xedni] == '0')
				mlx_put_image_to_window(data->mlx, data->window, \
					data->s[0].img, (xedni * 32), (i * 32));
			xedni++;
		}
		i++;
	}
}

void	sl_putimage_map_layer(t_data *data, int f)
{
	int	i;
	int	xedni;

	i = 0;
	while (data->map[i] != NULL)
	{
		xedni = 0;
		while (data->map[i][xedni] != '\0')
		{
			sl_putimage_map(data, f, i, xedni);
			xedni++;
		}
		i++;
	}
}

void	sl_putimage_map(t_data *d, int f, int i, int j)
{
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx, d->window, \
			d->w[0].img, (j * 32), (i * 32));
	else if (sl_checkcompair(NULL, "CEP", d->map[i][j], 2) != 0)
	{
		mlx_put_image_to_window(d->mlx, d->window, \
			d->s[0].img, (j * 32), (i * 32));
		if (d->map[i][j] == 'C')
			mlx_put_image_to_window(d->mlx, d->window, \
				d->c[f].img, (j * 32), (i * 32));
		else if (d->map[i][j] == 'E')
			mlx_put_image_to_window(d->mlx, d->window, \
				d->e[5].img, (j * 32), (i * 32));
		else if (d->map[i][j] == 'P')
		{
			sl_checkending(d, 2);
			d->x = i;
			d->y = j;
			if (d->end == 0 && d->wk <= 5)
				sl_walking_animate(d);
			else if (d->end == 0 && d->wk > 5)
				mlx_put_image_to_window(d->mlx, d->window, d->p[d->pf + f].img, \
					(j * 32), (i * 32));
		}
	}
}

void	sl_putimage_count(t_data *data)
{
	int	xedni;
	int	num;

	num = data->mc;
	xedni = sl_checklen(NULL, data->map[0], 2) - 1;
	while (xedni >= 0)
	{
		if (num != 0)
		{
			mlx_put_image_to_window(data->mlx, data->window, data->n[13].img, \
				xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
			mlx_put_image_to_window(data->mlx, data->window, data->n[num % 10 \
				].img, xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->window, data->n[14].img, \
				xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
			mlx_put_image_to_window(data->mlx, data->window, data->n[0].img, \
				xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
		}
		num = num / 10;
		xedni--;
	}
}
