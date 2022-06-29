#include "so_long.h"

void	sl_mon_patrolswap(t_data *data, int i, int fin, char tmp)
{
	int		j;

	srand(time(0));
	while (i < sl_checklen(data->mmap, NULL, 1))
	{
		j = 0;
		while(j < sl_checklen(NULL, data->mmap[i], 2))
		{
			if (data->mmap[i][j] == 'M' && data->u[i][j].k != 1)
			{
				fin = 0;
				data->u[i][j].mv = rand() % 5;
				if (data->u[i][j].mv < 4) 
				{
					fin += sl_checking_patroling_one(data, i, j, tmp);
					fin += sl_checking_patroling_two(data, i, j, tmp);
				}
				else if (data->u[i][j].mv == 4 && data->u[i][j].k == 0)
					fin = 1;
			}
			if (fin == 1)
				j++;
		}
		i++;
	}
}

int	sl_checking_patroling_one(t_data *data, int i, int j, char tmp)
{
	if (data->u[i][j].mv == 0 && data->u[i][j].k == 0 && \
		sl_checkcompair(NULL, "1ME", data->mmap[data->u[i][j].x - 1][data->u[i][j].y], 2) == 0)
	{
		tmp = data->mmap[data->u[i][j].x][data->u[i][j].y];
		data->mmap[data->u[i][j].x][data->u[i][j].y] = \
			data->mmap[data->u[i][j].x - 1][data->u[i][j].y];
		data->mmap[data->u[i][j].x - 1][data->u[i][j].y] = tmp;
		data->u[data->u[i][j].x - 1][data->u[i][j].y].pf = data->u[i][j].pf;
		data->u[data->u[i][j].x - 1][data->u[i][j].y].mv = data->u[i][j].mv;
		data->u[data->u[i][j].x - 1][data->u[i][j].y].k = 1;
		return (1);
	}
	else if (data->u[i][j].mv == 1 && data->u[i][j].k == 0 \
		&& sl_checkcompair(NULL, "1ME", data->mmap[data->u[i][j].x][data->u[i][j].y - 1], 2) == 0)
	{
		tmp = data->mmap[data->u[i][j].x][data->u[i][j].y];
		data->mmap[data->u[i][j].x][data->u[i][j].y] = \
			data->mmap[data->u[i][j].x][data->u[i][j].y - 1];
		data->mmap[data->u[i][j].x][data->u[i][j].y - 1] = tmp;
		data->u[data->u[i][j].x][data->u[i][j].y - 1].pf = 10;
		data->u[data->u[i][j].x][data->u[i][j].y - 1].mv = data->u[i][j].mv;
		data->u[data->u[i][j].x][data->u[i][j].y - 1].k = 1;
		return(1);
	}
	return (0);
}

int	sl_checking_patroling_two(t_data *data, int i, int j, char tmp)
{
	if (data->u[i][j].mv == 2 && data->u[i][j].k == 0 \
		&& sl_checkcompair(NULL, "1ME", data->mmap[data->u[i][j].x + 1][data->u[i][j].y], 2) == 0)
	{
		tmp = data->mmap[data->u[i][j].x][data->u[i][j].y];
		data->mmap[data->u[i][j].x][data->u[i][j].y] = \
			data->mmap[data->u[i][j].x + 1][data->u[i][j].y];
		data->mmap[data->u[i][j].x + 1][data->u[i][j].y] = tmp;
		data->u[data->u[i][j].x + 1][data->u[i][j].y].pf = data->u[i][j].pf;
		data->u[data->u[i][j].x + 1][data->u[i][j].y].mv = data->u[i][j].mv;
		data->u[data->u[i][j].x + 1][data->u[i][j].y].k = 1;
		return (1);
	}
	else if (data->u[i][j].mv == 3 && data->u[i][j].k == 0 \
		&& sl_checkcompair(NULL, "1ME", data->mmap[data->u[i][j].x][data->u[i][j].y + 1], 2) == 0 )
	{
		tmp = data->mmap[data->u[i][j].x][data->u[i][j].y];
		data->mmap[data->u[i][j].x][data->u[i][j].y] = \
			data->mmap[data->u[i][j].x][data->u[i][j].y + 1];
		data->mmap[data->u[i][j].x][data->u[i][j].y + 1] = tmp;
		data->u[data->u[i][j].x][data->u[i][j].y + 1].pf = 0;
		data->u[data->u[i][j].x][data->u[i][j].y + 1].mv = data->u[i][j].mv;
		data->u[data->u[i][j].x][data->u[i][j].y + 1].k = 1;
		return (1);
	}
	return(0);
}