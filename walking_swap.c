#include "so_long.h"

void	sl_check_collectible(t_data *data, int key, int index)
{
	int xedni;

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
		while (data->map[index] != NULL)
		{
			xedni = 0;
			while (data->map[index][xedni] != '\0')
			{
				if (data->map[index][xedni] == 'E')
					data->map[index][xedni] = '0';
				xedni++;
			}
			index++;
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
	// sl_check_collectible(data, mode, 0);
	data->wk = 1;
}

int	sl_walkswap(t_data *data, int mode)
{
	char	tmp;

	sl_check_collectible(data, mode, 0);
	sl_swapvalue(data, mode, tmp);
	if (mode == KEY_W)// && sl_checkcompair (0, "1E", d->map[d->x - 1][d->y], 2) == 0)// && data->map[data->x - 1][data->y] != 'E')/* up */
	{	
		// sl_check_collectible(data, mode, 0);
		// tmp = data->map[data->x][data->y];
		// data->map[data->x][data->y] = data->map[data->x - 1][data->y];
		// data->map[data->x - 1][data->y] = tmp;
		//sl_swapvalue(data, mode, tmp);
		data->key = KEY_W;
		// data->wk = 1;
	}
	else if (mode == KEY_A)// && data->map[data->x][data->y - 1] != '1' && data->map[data->x][data->y - 1] != 'E')/* left */
	{
		// sl_check_collectible(data, mode, 0);
		// tmp = data->map[data->x][data->y];
		// data->map[data->x][data->y] = data->map[data->x][data->y -1];
		// data->map[data->x][data->y - 1] = tmp;
		//sl_swapvalue(data, mode, tmp);
		data->key = KEY_A;
		// data->wk = 1;
	}
	else if (mode == KEY_S)// && data->map[data->x + 1][data->y] != '1' && data->map[data->x + 1][data->y] != 'E')/* down */
	{
		// sl_check_collectible(data, mode, 0);
		// tmp = data->map[data->x][data->y];
		// data->map[data->x][data->y] = data->map[data->x + 1][data->y];
		// data->map[data->x + 1][data->y] = tmp;
		//sl_swapvalue(data, mode, tmp)
		data->key = KEY_S;
		// data->wk = 1;
	}
	else if (mode == KEY_D)// && data->map[data->x][data->y + 1] != '1' && data->map[data->x][data->y + 1] != 'E')/* right */
	{
		// sl_check_collectible(data, mode, 0);
		// tmp = data->map[data->x][data->y];
		// data->map[data->x][data->y] = data->map[data->x][data->y + 1];
		// data->map[data->x][data->y + 1] = tmp;
		data->key = KEY_D;
		// data->wk = 1;
	}
	return (1);
}