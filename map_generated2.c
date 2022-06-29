#include "so_long.h"

void	sl_putimage_monster(t_data *data, int f)
{
	int	index;
	int	xedni;
	int count;

	count = 0;
	index = 0;
	while (data->mmap[index] != NULL)
	{
		xedni = 0;
		while (data->mmap[index][xedni] != '\0')
		{
			sl_putimage_mmap(data, index, xedni, f);
			xedni++;
		}
		index++;
	}
}

void	sl_putimage_mmap(t_data *data, int index, int xedni, int f)
{
	if (data->mmap[index][xedni] == 'E')
	{
		if (sl_checkcompair(data->map, NULL, 'C', 1) == 0)
			mlx_put_image_to_window(data->mlx, data->window, \
				data->e[5].img, (xedni * 32), (index * 32));
		else
			mlx_put_image_to_window(data->mlx, data->window, \
				data->e[f % 5].img, (xedni * 32), (index * 32));
		}
		else if (data->mmap[index][xedni] == 'M')
		{
			data->u[index][xedni].x = index;
			data->u[index][xedni].y = xedni;
			if (data->wk <= 5 && data->u[index][xedni].mv != 4)
				sl_patroling_animate(data, index, xedni, 1);
			else
				mlx_put_image_to_window(data->mlx, data->window, \
					data->m[data->u[index][xedni].pf + f].img, (xedni * 32), (index * 32));
			data->u[index][xedni].k = 0;
		}
}