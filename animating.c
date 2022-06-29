/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:31:18 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 22:49:55 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_walking_animate(t_data *d)
{	
	if (d->end == 1)
		mlx_put_image_to_window(d->mlx, d->window, \
			d->e[5].img, d->y * 32, d->x * 32);
	else
		mlx_put_image_to_window(d->mlx, d->window, \
			d->s[0].img, d->y * 32, d->x * 32);
	if (d->key == KEY_A)
		mlx_put_image_to_window(d->mlx, d->window, d->p[24 + d->wk].img, \
			((d->y + 1) * 32) - (6 * d->wk), d->x * 32);
	else if (d->key == KEY_S)
		mlx_put_image_to_window(d->mlx, d->window, d->p[(19 + (d->pf / 2)) + \
			d->wk].img, d->y * 32, ((d->x - 1) * 32) + (6 * d->wk));
	else if (d->key == KEY_D)
		mlx_put_image_to_window(d->mlx, d->window, \
			d->p[19 + d->wk].img, ((d->y - 1) * 32) + (6 * d->wk), d->x * 32);
	else if (d->key == KEY_W)
		mlx_put_image_to_window(d->mlx, d->window, \
			d->p[(19 + (d->pf / 2)) + d->wk].img, d->y * 32, \
			((d->x + 1) * 32) - (6 * d->wk));
}

void	sl_patroling_animate(t_data *d, int i, int j, int mode)
{
	if ((d->u[i][j].kil == 0 && mode == 1) || \
		(mode == 2 && d->end == 3))
	{
		sl_patroling_animate_normal(d, i, j);
	}
	else if (mode == 2 && d->end == 2)
	{
		sl_patroling_animate_spacial(d, i, j);
	}
}

void	sl_patroling_animate_normal(t_data *d, int i, int j)
{
	if (d->u[i][j].mv == 1)
		mlx_put_image_to_window(d->mlx, d->window, d->m[24 + d->wk].img, \
			((d->u[i][j].y + 1) * 32) - (6 * d->wk), d->u[i][j].x * 32);
	else if (d->u[i][j].mv == 2)
		mlx_put_image_to_window(d->mlx, d->window, d->m[(19 + (d->u[i][j].pf \
			/ 2)) + d->wk].img, d->u[i][j].y * 32, ((d->u[i][j].x - 1) * 32) \
			+ (6 * d->wk));
	else if (d->u[i][j].mv == 3)
		mlx_put_image_to_window(d->mlx, d->window, d->m[19 + d->wk].img, \
			((d->u[i][j].y - 1) * 32) + (6 * d->wk), d->u[i][j].x * 32);
	else if (d->u[i][j].mv == 0)
		mlx_put_image_to_window(d->mlx, d->window, d->m[(19 + (d->u[i][j].pf \
		/ 2)) + d->wk].img, d->u[i][j].y * 32, ((d->u[i][j].x + 1) * 32) - \
		(6 * d->wk));
}

void	sl_patroling_animate_spacial(t_data *d, int i, int j)
{
	if (d->u[i][j].mv == 1)
		mlx_put_image_to_window(d->mlx, d->window, d->m[24 + d->wk].img, \
			((d->u[i][j].y) * 32) - (6 * d->wk), d->u[i][j].x * 32);
	else if (d->u[i][j].mv == 2)
		mlx_put_image_to_window(d->mlx, d->window, d->m[(19 + (d->u[i][j].pf \
			/ 2)) + d->wk].img, d->u[i][j].y * 32, ((d->u[i][j].x) * 32) \
			+ (6 * d->wk));
	else if (d->u[i][j].mv == 3)
		mlx_put_image_to_window(d->mlx, d->window, d->m[19 + d->wk].img, \
			((d->u[i][j].y) * 32) + (6 * d->wk), d->u[i][j].x * 32);
	else if (d->u[i][j].mv == 0)
		mlx_put_image_to_window(d->mlx, d->window, d->m[(19 + (d->u[i][j].pf \
			/ 2)) + d->wk].img, d->u[i][j].y * 32, ((d->u[i][j].x) * 32) - \
			(6 * d->wk));
}
