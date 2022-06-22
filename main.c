/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:33:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/23 05:27:13 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"


	/* function finding a charactor in a string */
		/* mode1 = finding in 2 stars || mode2 = finding in 1 stars */
int	sl_checkcompair(char **rts, char *str, char c, int mode)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	if (rts == NULL && mode == 1 || str == NULL && mode == 2)
		return (0);
	if (mode == 1)
	{
		while (rts[index] != NULL)
		{
//			if (sl_checkcompair(NULL, rts[index], c, 2) != 0)
				count += sl_checkcompair(NULL, rts[index], c, 2);//return (1);
			index++;
		}
	}
	if (mode == 2)
	{
		while (str[index] != '\0')
		{	
			if (str[index] == c)
				count += 1;//return (1);
			index++;
		}
	}
	return (count);
}

void	sl_walking_animate(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, data->y * 32, data->x * 32);
	if (data->key == KEY_LEFT)
		mlx_put_image_to_window(data->mlx, data->window, data->p[24 + data->wk].img, ((data->y + 1) * 32) - (6 * data->wk), data->x * 32);
	else if (data->key == KEY_DOWN)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + (6 * data->wk));
	else if (data->key == KEY_RIGHT)
		mlx_put_image_to_window(data->mlx, data->window, data->p[19 + data->wk].img, ((data->y - 1) * 32) + (6 * data->wk), data->x * 32);
	else if (data->key == KEY_UP)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - (6 * data->wk));
	data->wk += 1;
}

void	sl_patroling_animate(t_data *data, int count)
{
	return ;

}


void	sl_map_generate(t_data *data, int f)
{
	t_file	img1;
	int	count;
	int index;

	index = 0;
	img1.img = mlx_xpm_file_to_image(data->mlx, "./images/1/1.xpm", &img1.wid, &img1.hei);
	data->s[0].img = mlx_xpm_file_to_image(data->mlx, "./images/0/01.xpm", &data->s[0].wid, &data->s[0].hei); 
//	data->s[1].img = mlx_xpm_file_to_image(data->mlx, "./images/0/001.xpm", &data->s[1].wid, &data->s[1].hei); 
	data->p[0].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P1.xpm", &data->p[0].wid, &data->p[0].hei);
	data->p[1].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P2.xpm", &data->p[1].wid, &data->p[1].hei);
	data->p[2].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P3.xpm", &data->p[2].wid, &data->p[2].hei);
	data->p[3].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P4.xpm", &data->p[3].wid, &data->p[3].hei);
	data->p[4].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P5.xpm", &data->p[4].wid, &data->p[4].hei);
	data->p[5].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P6.xpm", &data->p[5].wid, &data->p[5].hei);
	data->p[6].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P7.xpm", &data->p[6].wid, &data->p[6].hei);
	data->p[7].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P8.xpm", &data->p[7].wid, &data->p[7].hei);
	data->p[8].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P9.xpm", &data->p[8].wid, &data->p[8].hei);
	data->p[9].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P0.xpm", &data->p[9].wid, &data->p[9].hei);
	data->p[10].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb1.xpm", &data->p[10].wid, &data->p[10].hei);
	data->p[11].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb2.xpm", &data->p[11].wid, &data->p[11].hei);
	data->p[12].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb3.xpm", &data->p[12].wid, &data->p[12].hei);
	data->p[13].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb4.xpm", &data->p[13].wid, &data->p[13].hei);
	data->p[14].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb5.xpm", &data->p[14].wid, &data->p[14].hei);
	data->p[15].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb6.xpm", &data->p[15].wid, &data->p[15].hei);
	data->p[16].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb7.xpm", &data->p[16].wid, &data->p[16].hei);
	data->p[17].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb8.xpm", &data->p[17].wid, &data->p[17].hei);
	data->p[18].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb9.xpm", &data->p[18].wid, &data->p[18].hei);
	data->p[19].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pb0.xpm", &data->p[19].wid, &data->p[19].hei);
	data->p[20].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pr1.xpm", &data->p[20].wid, &data->p[20].hei);
	data->p[21].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pr2.xpm", &data->p[21].wid, &data->p[21].hei);
	data->p[22].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pr3.xpm", &data->p[22].wid, &data->p[22].hei);
	data->p[23].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pr4.xpm", &data->p[23].wid, &data->p[23].hei);
	data->p[24].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pr5.xpm", &data->p[24].wid, &data->p[24].hei);
	data->p[25].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbr1.xpm", &data->p[25].wid, &data->p[25].hei);
	data->p[26].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbr2.xpm", &data->p[26].wid, &data->p[26].hei);
	data->p[27].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbr3.xpm", &data->p[27].wid, &data->p[27].hei);
	data->p[28].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbr4.xpm", &data->p[28].wid, &data->p[28].hei);
	data->p[29].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbr5.xpm", &data->p[29].wid, &data->p[29].hei);
	data->c[0].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C1.xpm", &data->c[0].wid, &data->c[0].hei);
	data->c[1].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C2.xpm", &data->c[1].wid, &data->c[1].hei);
	data->c[2].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C3.xpm", &data->c[2].wid, &data->c[2].hei);
	data->c[3].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C4.xpm", &data->c[3].wid, &data->c[3].hei);
	data->c[4].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C5.xpm", &data->c[4].wid, &data->c[4].hei);
	data->c[5].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C6.xpm", &data->c[5].wid, &data->c[5].hei);
	data->c[6].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C7.xpm", &data->c[6].wid, &data->c[6].hei);
	data->c[7].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C8.xpm", &data->c[7].wid, &data->c[7].hei);
	data->c[8].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C9.xpm", &data->c[8].wid, &data->c[8].hei);
	data->c[9].img = mlx_xpm_file_to_image(data->mlx, "./images/C/C5.xpm", &data->c[9].wid, &data->c[9].hei);
	data->e[0].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E1.xpm", &data->e[0].wid, &data->e[0].hei);
//	data->e[1].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E2.xpm", &data->e[1].wid, &data->e[1].hei);
//	data->e[2].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E3.xpm", &data->e[2].wid, &data->e[2].hei);
//	data->e[3].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E4.xpm", &data->e[3].wid, &data->e[3].hei);
//	data->e[4].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E5.xpm", &data->e[4].wid, &data->e[4].hei);
	data->m[0].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M9.xpm", &data->m[0].wid, &data->m[0].hei);
	data->m[1].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M0.xpm", &data->m[1].wid, &data->m[1].hei);
	data->m[2].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M1.xpm", &data->m[2].wid, &data->m[2].hei);
	data->m[3].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M2.xpm", &data->m[3].wid, &data->m[3].hei);
	data->m[4].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M3.xpm", &data->m[4].wid, &data->m[4].hei);
	data->m[5].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M4.xpm", &data->m[5].wid, &data->m[5].hei);
	data->m[6].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M5.xpm", &data->m[6].wid, &data->m[6].hei);
	data->m[7].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M6.xpm", &data->m[7].wid, &data->m[7].hei);
	data->m[8].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M7.xpm", &data->m[8].wid, &data->m[8].hei);
	data->m[9].img = mlx_xpm_file_to_image(data->mlx, "./images/M/M8.xpm", &data->m[9].wid, &data->m[9].hei);
	data->m[10].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb1.xpm", &data->m[10].wid, &data->m[10].hei);
	data->m[11].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb2.xpm", &data->m[11].wid, &data->m[11].hei);
	data->m[12].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb3.xpm", &data->m[12].wid, &data->m[12].hei);
	data->m[13].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb4.xpm", &data->m[13].wid, &data->m[13].hei);
	data->m[14].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb5.xpm", &data->m[14].wid, &data->m[14].hei);
	data->m[15].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb6.xpm", &data->m[15].wid, &data->m[15].hei);
	data->m[16].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb7.xpm", &data->m[16].wid, &data->m[16].hei);
	data->m[17].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb8.xpm", &data->m[17].wid, &data->m[17].hei);
	data->m[18].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb9.xpm", &data->m[18].wid, &data->m[18].hei);
	data->m[19].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mb0.xpm", &data->m[19].wid, &data->m[19].hei);
	data->m[20].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mr1.xpm", &data->m[20].wid, &data->m[20].hei);
	data->m[21].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mr2.xpm", &data->m[21].wid, &data->m[21].hei);
	data->m[22].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mr3.xpm", &data->m[22].wid, &data->m[22].hei);
	data->m[23].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mr4.xpm", &data->m[23].wid, &data->m[23].hei);
	data->m[24].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mr5.xpm", &data->m[24].wid, &data->m[24].hei);
	data->m[25].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mbr1.xpm", &data->m[25].wid, &data->m[25].hei);
	data->m[26].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mbr2.xpm", &data->m[26].wid, &data->m[26].hei);
	data->m[27].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mbr3.xpm", &data->m[27].wid, &data->m[27].hei);
	data->m[28].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mbr4.xpm", &data->m[28].wid, &data->m[28].hei);
	data->m[29].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mbr5.xpm", &data->m[29].wid, &data->m[29].hei);

	mlx_clear_window(data->mlx, data->window);
	while (data->map[index] != NULL)
	{
		int xedni = 0;
		while (data->map[index][xedni] != '\0')
		{
			if (data->map[index][xedni] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (xedni * 32), (index * 32));
			xedni++;
		}
		index++;
	}
	index = 0;
	while (data->map[index] != NULL)
	{
		int xedni = 0;
		while (data->map[index][xedni] != '\0')
		{
			if (data->map[index][xedni] == '1')
				mlx_put_image_to_window(data->mlx, data->window, img1.img, (xedni * 32), (index * 32));
			else if (sl_checkcompair(NULL, "CEP", data->map[index][xedni], 2) != 0)
			{
				mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (xedni * 32), (index * 32));
				if (data->map[index][xedni] == 'C')
					mlx_put_image_to_window(data->mlx, data->window, data->c[f].img, (xedni * 32), (index * 32));
				else if (data->map[index][xedni] == 'E')
					mlx_put_image_to_window(data->mlx, data->window, data->e[0].img, (xedni * 32), (index * 32));
				else if (data->map[index][xedni] == 'P')
				{
					data->x = index;
					data->y = xedni;
					if (data->wk <= 5)
					{
						sl_walking_animate(data);
					}
					else
					{
						mlx_put_image_to_window(data->mlx, data->window, data->p[data->pf + f].img, (xedni * 32), (index * 32));
					}
				}
			}
			xedni++;
		}
		index++;
	}
	count = 0;
	index = 0;
	while (data->mmap[index] != NULL)
	{
		int xedni = 0;
		while (data->mmap[index][xedni] != '\0')
		{
			if (data->mmap[index][xedni] == 'M')
			{
				data->u[count].x = index;
				data->u[count].y = xedni;
				if (data->wk <= 5)
				{
					//sl_partroling_animate(data);
				}
				else
				{
					mlx_put_image_to_window(data->mlx, data->window, data->m[data->u[count].pf + f].img, (xedni * 32), (index * 32));
				}
				count++;
			}
			xedni++;
		}
		index++;
	}
//	return (map);
}

int	sl_walkswap(t_data *data, int mode)
{
	char	tmp;

	if (mode == KEY_UP && data->map[data->x - 1][data->y] != '1')/* up */
	{	
		if (data->map[data->x - 1][data->y] == 'C')
			data->map[data->x - 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x - 1][data->y];
		data->map[data->x - 1][data->y] = tmp;
		data->key = KEY_UP;
		data->wk = 1;
	}
	else if (mode == KEY_LEFT && data->map[data->x][data->y - 1] != '1')/* left */
	{
		if (data->map[data->x][data->y -1] == 'C')
			data->map[data->x][data->y -1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y -1];
		data->map[data->x][data->y - 1] = tmp;
		data->key = KEY_LEFT;
		data->wk = 1;
	}
	else if (mode == KEY_DOWN && data->map[data->x + 1][data->y] != '1')/* down */
	{
		if (data->map[data->x + 1][data->y] == 'C')
			data->map[data->x + 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x + 1][data->y];
		data->map[data->x + 1][data->y] = tmp;
		data->key = KEY_DOWN;
		data->wk = 1;
	}
	else if (mode == KEY_RIGHT && data->map[data->x][data->y + 1] != '1')/* right */
	{
		if (data->map[data->x][data->y + 1] == 'C')
			data->map[data->x][data->y + 1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y + 1];
		data->map[data->x][data->y + 1] = tmp;
		data->key = KEY_RIGHT;
		data->wk = 1;
	}
	return (1);
}

int	sl_mon_patrolswap(t_data *data)
{
	char	tmp;
	int		index;
	int		fin;

	index = 0;
	srand(time(0));
	while (index < sl_checkcompair(data->mmap, NULL, 'M', 1))//(data->u[index] == NULL)//
	{
		fin = 0;
		data->u[index].mv = rand();
		printf("index = %d, mv = %d\n", index, data->u[index].mv % 5);
		if (data->u[index].mv % 5 == 0 && data->mmap[data->u[index].x - 1][data->u[index].y] != '1')// && data->mmap[data->u[index].x - 1][data->u[index].y] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x - 1][data->u[index].y];
			data->mmap[data->u[index].x - 1][data->u[index].y] = tmp;
			fin = 1;
		}
		else if (data->u[index].mv % 5 == 1 && data->mmap[data->u[index].x][data->u[index].y - 1] != '1')// && data->mmap[data->u[index].x][data->u[index].y - 1] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x][data->u[index].y - 1];
			data->mmap[data->u[index].x][data->u[index].y - 1] = tmp;
			data->u[index].pf = 10;
			fin = 1;

		}
		else if (data->u[index].mv % 5 == 2 && data->mmap[data->u[index].x + 1][data->u[index].y] != '1')// && data->mmap[data->u[index].x + 1][data->u[index].y] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x + 1][data->u[index].y];
			data->mmap[data->u[index].x + 1][data->u[index].y] = tmp;
			fin = 1;
		}
		else if (data->u[index].mv % 5 == 3 && data->mmap[data->u[index].x][data->u[index].y + 1] != '1')// && data->mmap[data->u[index].x][data->u[index].y + 1] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x][data->u[index].y + 1];
			data->mmap[data->u[index].x][data->u[index].y + 1] = tmp;
			data->u[index].pf = 0;
			fin = 1;

		}
		else if (data->u[index].mv % 5 == 4)
			fin = 1;
		if (fin == 1)
			index++;
	}
	return (1);
}

int	sl_keyinput(int keycode, t_data *data)
{
	static int	count = 0;

	if (keycode == KEY_LEFT && data->y > 0 && data->wk > 5)// || keycode == KEY_A)
	{
		count += sl_walkswap(data, KEY_LEFT);
		sl_mon_patrolswap(data);
		data->pf = 10;
		printf("movement count == %d\n", count);
		twostarstools(data->map, 1);
		twostarstools(data->mmap, 1);
	}
	else if (keycode == KEY_DOWN && data->x < sl_checklen(data->map, NULL, 1) - 1 && data->wk > 5)//|| keycode == KEY_S)
	{
		count += sl_walkswap(data, KEY_DOWN);
		sl_mon_patrolswap(data);
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_RIGHT && data->y < sl_checklen(NULL, data->map[0], 2) - 1 && data->wk > 5)//|| keycode == KEY_D)
	{
		count += sl_walkswap(data, KEY_RIGHT);
		sl_mon_patrolswap(data);
		data->pf = 0;
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_UP && data->x > 0 && data->wk > 5)// || keycode == KEY_W)
	{ 
		count += sl_walkswap(data, KEY_UP);
		sl_mon_patrolswap(data);
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		// destroy images //
		twostarstools(data->map, 0);
		free(data);
		printf("END FUNCTION\n");
		exit(0);
	}
//	sl_map_generate(data, 0);
	return (0);
}

int	sl_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	twostarstools(data->map, 0);
	free(data);
	exit(0);
	return (0);
}

int	sl_animating(t_data *data)
{
	static int	count = 0;

	if (count >= 11109)
		count = 0;
	if (count % 1111 == 0)
	{
		sl_map_generate(data, count / 1111);
	}
	count = count + 1;

	return (0);
}

int sl_p_moving(int key, t_data *data)
{
	if (key == KEY_RIGHT)
	{
	//	printf("x = %d, y = %d, test = %d\n", data->x * 32, data->y * 32, data->test);
	//	mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + (6 * data->test), data->x * 32);
	//	mlx_put_image_to_window(data->mlx, data->window, data->p[20].img, (data->y * 32) + (6 * data->test), data->x * 32);
/*		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 12, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[21].img, (data->y * 32) + 12, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 18, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[22].img, (data->y * 32) + 18, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 24, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[23].img, (data->y * 32) + 24, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 30, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[24].img, (data->y * 32) + 30, data->x * 32);
		sleep (1);
*/	}
	return (0);
}
/*
int sl_p_moving(int key, t_data *data)
{
	if (key == KEY_RIGHT)
	{
		printf("x = %d, y = %d\n", data->x * 32, data->y * 32 + 6);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 6, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[20].img, (data->y * 32) + 6, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 12, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[21].img, (data->y * 32) + 12, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 18, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[22].img, (data->y * 32) + 18, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 24, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[23].img, (data->y * 32) + 24, data->x * 32);
		sleep (1);
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, (data->y * 32) + 30, (data->x * 32));
		mlx_put_image_to_window(data->mlx, data->window, data->p[24].img, (data->y * 32) + 30, data->x * 32);
		sleep (1);
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc != 2)
	{	
		write(1, "WRONG ARGUMENT\n", 15);
		return (0);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	data->wk = 6;
	data->map = sl_read_map(argv);
	twostarstools(data->map, 1);
	data->mmap = sl_make_mmap(data->map);
	data->map = sl_make_map(data->map);

	printf("count M = %d\n", sl_checkcompair(data->mmap, NULL, 'M', 1));
/*	data->u = (t_char*)malloc(sizeof(t_char) + sl_checkcompair(data->mmap, NULL, 'M', 1));
	if (data->u == NULL)
	{
		//free another things//
		return (0);
	}*/


	
	int width = 32 * sl_checklen(NULL, data->map[0], 2);
	int height = 32 * sl_checklen(data->map, NULL, 1);
	
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, width, height, "so_long");
	mlx_hook(data->window, 17, 0, sl_close, data);
	mlx_hook(data->window, 2, 1L<<2,  sl_p_moving, data);
//	mlx_hook(data->window, 3, 1L<<1,  sl_keyinput, data);
	mlx_key_hook(data->window, sl_keyinput, data);
	sl_map_generate(data, 0);
	printf("Hello\n");


	mlx_loop_hook(data->mlx, sl_animating, data);
	

	mlx_loop(data->mlx);
	twostarstools(data->map, 0);
	free(data);
	return (0);
}
