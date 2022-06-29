/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generated2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:50:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:50:49 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_putimage_monster(t_data *data, int f)
{
	int	i;
	int	xedni;
	int	count;

	count = 0;
	i = 0;
	while (data->mmap[i] != NULL)
	{
		xedni = 0;
		while (data->mmap[i][xedni] != '\0')
		{
			sl_putimage_mmap(data, i, xedni, f);
			xedni++;
		}
		i++;
	}
}

void	sl_putimage_mmap(t_data *data, int i, int xedni, int f)
{
	if (data->mmap[i][xedni] == 'E')
	{
		if (sl_checkcompair(data->map, NULL, 'C', 1) == 0)
			mlx_put_image_to_window(data->mlx, data->window, \
				data->e[5].img, (xedni * 32), (i * 32));
		else
			mlx_put_image_to_window(data->mlx, data->window, \
				data->e[f % 5].img, (xedni * 32), (i * 32));
	}
	else if (data->mmap[i][xedni] == 'M')
	{
		data->u[i][xedni].x = i;
		data->u[i][xedni].y = xedni;
		if (data->wk <= 5 && data->u[i][xedni].mv != 4)
			sl_patroling_animate(data, i, xedni, 1);
		else
			mlx_put_image_to_window(data->mlx, data->window, \
				data->m[data->u[i][xedni].pf + f].img, (xedni * 32), (i * 32));
		data->u[i][xedni].k = 0;
	}
}
