#include "so_long.h"

void	sl_map_generate(t_data *data, int f)
{
	mlx_clear_window(data->mlx, data->window);
	sl_putimage_space_layer(data);
	sl_putimage_map_layer(data, f);
	sl_checkending(data, 3);
	sl_putimage_monster(data, f);
	sl_checkending(data, 1);
	if (data->wk <= 5 && data->end != 0 || data->end == 1)
			sl_ending_screen(data, f);
	sl_putimage_count(data);
	data->wk += 1;
}

void	sl_putimage_space_layer(t_data *data)
{
	int	count;
	int index;
	int	xedni;

	index = 0;
	while (data->map[index] != NULL)
	{
		xedni = 0;
		while (data->map[index][xedni] != '\0')
		{
			if (data->map[index][xedni] == '0')
				mlx_put_image_to_window(data->mlx, data->window,\
					data->s[0].img, (xedni * 32), (index * 32));
			xedni++;
		}
		index++;
	}
}

void	sl_putimage_map_layer(t_data *data, int f)
{
	int index;
	int xedni;

	index = 0;
	while (data->map[index] != NULL)
	{
		xedni = 0;
		while (data->map[index][xedni] != '\0')
		{
			sl_putimage_map(data, f, index, xedni);
			xedni++;
		}
		index++;
	}
}


void	sl_putimage_map(t_data *d, int f, int i, int j)
{
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx, d->window,\
			d->w[0].img, (j * 32), (i * 32));
	else if (sl_checkcompair(NULL, "CEP", d->map[i][j], 2) != 0)
	{
		mlx_put_image_to_window(d->mlx, d->window,\
			d->s[0].img, (j * 32), (i * 32));
		if (d->map[i][j] == 'C')
			mlx_put_image_to_window(d->mlx, d->window,\
				d->c[f].img, (j * 32), (i * 32));
		else if (d->map[i][j] == 'E')
			mlx_put_image_to_window(d->mlx, d->window,\
				d->e[5].img, (j * 32), (i * 32));
		else if (d->map[i][j] == 'P')
		{
			sl_checkending(d, 2);
			d->x = i;
			d->y = j;
			if (d->end == 0 && d->wk <= 5)
				sl_walking_animate(d);
			else if (d->end == 0 && d->wk > 5)
				mlx_put_image_to_window(d->mlx, d->window, d->p[d->pf + f].img,\
					(j * 32), (i * 32));
		}
	}
}

// void	sl_putimage_monster(t_data *data, int f)
// {
// 	int	index;
// 	int	xedni;
// 	int count;

// 	count = 0;
// 	index = 0;
// 	while (data->mmap[index] != NULL)
// 	{
// 		xedni = 0;
// 		while (data->mmap[index][xedni] != '\0')
// 		{
// 			sl_putimage_mmap(data, index, xedni, f);
// 			xedni++;
// 		}
// 		index++;
// 	}
// }

// void	sl_putimage_mmap(t_data *data, int index, int xedni, int f)
// {
// 	if (data->mmap[index][xedni] == 'E')
// 	{
// 		if (sl_checkcompair(data->map, NULL, 'C', 1) == 0)
// 			mlx_put_image_to_window(data->mlx, data->window, \
// 				data->e[5].img, (xedni * 32), (index * 32));
// 		else
// 			mlx_put_image_to_window(data->mlx, data->window, \
// 				data->e[f % 5].img, (xedni * 32), (index * 32));
// 		}
// 		else if (data->mmap[index][xedni] == 'M')
// 		{
// 			data->u[index][xedni].x = index;
// 			data->u[index][xedni].y = xedni;
// 			if (data->wk <= 5 && data->u[index][xedni].mv != 4)
// 				sl_patroling_animate(data, index, xedni, 1);
// 			else
// 				mlx_put_image_to_window(data->mlx, data->window, \
// 					data->m[data->u[index][xedni].pf + f].img, (xedni * 32), (index * 32));
// 			data->u[index][xedni].k = 0;
// 		}
// }

void	sl_putimage_count(t_data *data)
{
	int xedni;
	int num;
	
	num = data->mc;
	xedni = sl_checklen(NULL, data->map[0], 2) - 1;
	while (xedni >= 0)
	{
		if (num != 0)
		{
			mlx_put_image_to_window(data->mlx, data->window, \
				data->n[13].img, xedni *32, (sl_checklen(data->map, NULL, 1 ) - 1) * 32);
			mlx_put_image_to_window(data->mlx, data->window, \
				data->n[num % 10].img, xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->window, \
				data->n[14].img, xedni *32, (sl_checklen(data->map, NULL, 1 ) - 1) * 32);
			mlx_put_image_to_window(data->mlx, data->window, \
				data->n[0].img, xedni * 32, (sl_checklen(data->map, NULL, 1) - 1) * 32);
		}
		num = num / 10;
		xedni--;
	}
}