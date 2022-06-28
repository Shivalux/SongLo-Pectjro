/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:33:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/28 09:03:53 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"

int		sl_checkending(t_data *data, int mode);
void	sl_ending_screen(t_data *data, int f);

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
{	if (data->end == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->e[5].img, data->y * 32, data->x * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->s[0].img, data->y * 32, data->x * 32);
	if (data->key == KEY_A)
		mlx_put_image_to_window(data->mlx, data->window, data->p[24 + data->wk].img, ((data->y + 1) * 32) - (6 * data->wk), data->x * 32);
	else if (data->key == KEY_S)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + (6 * data->wk));
	else if (data->key == KEY_D)
		mlx_put_image_to_window(data->mlx, data->window, data->p[19 + data->wk].img, ((data->y - 1) * 32) + (6 * data->wk), data->x * 32);
	else if (data->key == KEY_W)
		mlx_put_image_to_window(data->mlx, data->window, data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - (6 * data->wk));
}

void	sl_patroling_animate(t_data *data, int index, int xedni, int mode)
{
	if (data->u[index][xedni].kil == 0 && mode == 1 || mode == 2 && data->end == 3)
	{
		if (data->u[index][xedni].mv == 1)
			mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, ((data->u[index][xedni].y + 1) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 2)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x - 1) * 32) + (6 * data->wk));
		else if (data->u[index][xedni].mv == 3)
			mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, ((data->u[index][xedni].y - 1) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x + 1) * 32) - (6 * data->wk));
	}
	else if (mode == 2 && data->end == 2)
	{
		if (data->u[index][xedni].mv == 1)
			mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, ((data->u[index][xedni].y) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 2)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) + (6 * data->wk));
		else if (data->u[index][xedni].mv == 3)
			mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, ((data->u[index][xedni].y) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) - (6 * data->wk));
	}
/*	else if (mode == 2 && data->end == 2)
	{
		if (data->u[index][xedni].mv == 1)
			mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, ((data->u[index][xedni].y) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 2)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) + (6 * data->wk));
		else if (data->u[index][xedni].mv == 3)
			mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, ((data->u[index][xedni].y) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) - (6 * data->wk));
	}*/
}

// 	/* fucntion about ending of player */
// 		/* mode1: 'P' same position with 'E' | mode3: 'P' same position with
// 		  'M' | mode2: move and touching a Monster */
// int		sl_checkending_player(t_data *data, int mode)
// {

// 	if (mode == 1 && data->mmap[data->x][data->y] == 'E')
// 		return (1);
// 	else if (mode == 2) // && data->wk == 1;
// 	{
// 		if (data->mmap[data->x][data->y] == 'M' && data->u[data->x][data->y].mv == 2 && data->key == KEY_W)
// 			return (2);
// 		else if (data->mmap[data->x][data->y] == 'M' && data->u[data->x][data->y].mv == 3 && data->key == KEY_A)
// 			return (2);
// 		else if (data->mmap[data->x][data->y] == 'M' && data->u[data->x][data->y].mv == 0 && data->key == KEY_S)
// 			return (2);
// 		else if (data->mmap[data->x][data->y] == 'M' && data->u[data->x][data->y].mv == 1 && data->key == KEY_D)
// 			return (2);
// 	}
// 	else if (mode == 3 && data->mmap[data->x][data->y] == 'M')
// 		return (3);
// 	return (0);
// }

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
	data->p[30].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pd1.xpm", &data->p[30].wid, &data->p[30].hei);
	data->p[31].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pd2.xpm", &data->p[31].wid, &data->p[31].hei);
	data->p[32].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pd3.xpm", &data->p[32].wid, &data->p[32].hei);
	data->p[33].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pd4.xpm", &data->p[33].wid, &data->p[33].hei);
	data->p[34].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pd5.xpm", &data->p[34].wid, &data->p[34].hei);
	data->p[35].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbd1.xpm", &data->p[35].wid, &data->p[35].hei);
	data->p[36].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbd2.xpm", &data->p[36].wid, &data->p[36].hei);
	data->p[37].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbd3.xpm", &data->p[37].wid, &data->p[37].hei);
	data->p[38].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbd4.xpm", &data->p[38].wid, &data->p[38].hei);
	data->p[39].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pbd5.xpm", &data->p[39].wid, &data->p[39].hei);
	data->p[40].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pw4.xpm", &data->p[40].wid, &data->p[40].hei);
	data->p[41].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pw2.xpm", &data->p[41].wid, &data->p[41].hei);
	data->p[42].img = mlx_xpm_file_to_image(data->mlx, "./images/P/Pw3.xpm", &data->p[42].wid, &data->p[42].hei);
	data->p[43].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P7.xpm", &data->p[43].wid, &data->p[43].hei);
	data->p[44].img = mlx_xpm_file_to_image(data->mlx, "./images/P/P8.xpm", &data->p[44].wid, &data->p[44].hei);
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
	data->e[1].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E2.xpm", &data->e[1].wid, &data->e[1].hei);
	data->e[2].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E3.xpm", &data->e[2].wid, &data->e[2].hei);
	data->e[3].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E4.xpm", &data->e[3].wid, &data->e[3].hei);
	data->e[4].img = mlx_xpm_file_to_image(data->mlx, "./images/E/E5.xpm", &data->e[4].wid, &data->e[4].hei);
	data->e[5].img = mlx_xpm_file_to_image(data->mlx, "./images/E/EE7.xpm", &data->e[5].wid, &data->e[5].hei);
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
	data->m[30].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Ma1.xpm", &data->m[30].wid, &data->m[30].hei);
	data->m[31].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Ma2.xpm", &data->m[31].wid, &data->m[31].hei);
	data->m[32].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Ma3.xpm", &data->m[32].wid, &data->m[32].hei);
	data->m[33].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Ma4.xpm", &data->m[33].wid, &data->m[33].hei);
	data->m[34].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Ma5.xpm", &data->m[34].wid, &data->m[34].hei);
	data->m[35].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mba1.xpm", &data->m[35].wid, &data->m[35].hei);
	data->m[36].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mba2.xpm", &data->m[36].wid, &data->m[36].hei);
	data->m[37].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mba3.xpm", &data->m[37].wid, &data->m[37].hei);
	data->m[38].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mba4.xpm", &data->m[38].wid, &data->m[38].hei);
	data->m[39].img = mlx_xpm_file_to_image(data->mlx, "./images/M/Mba5.xpm", &data->m[39].wid, &data->m[39].hei);

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
					mlx_put_image_to_window(data->mlx, data->window, data->e[5].img, (xedni * 32), (index * 32));
				else if (data->map[index][xedni] == 'P')
				{
					// if (data->wk == 1 && sl_checkending_player(data, 2) == 2)
					if (data->wk == 1 && sl_checkending(data, 2) == 2)
					 	printf("DEAD WITH MOVING TOUCHING WIHT A MONSTER 55\n");
					data->x = index;
					data->y = xedni;
					// check monster around and its mv // if suan gun = dead
					if (data->end == 0 && data->wk <= 5)
					{
						sl_walking_animate(data);
					}
					else if (data->end == 0 && data->wk > 5)
					{
						mlx_put_image_to_window(data->mlx, data->window, data->p[data->pf + f].img, (xedni * 32), (index * 32));
					}
				}
			}
			xedni++;
		}
		index++;
	}
	if (data->wk == 1 && data->end == 0 && sl_checkending(data, 3) == 3)
		printf("DEAD IN SAME POSITION WITH A  MONSTER\n");
	int	tnuoc = 0;
	count = 0;
	index = 0;
	while (data->mmap[index] != NULL)
	{
		int xedni = 0;
		while (data->mmap[index][xedni] != '\0')
		{
			if (data->mmap[index][xedni] == 'E')
			{
				if (sl_checkcompair(data->map, NULL, 'C', 1) == 0)
					mlx_put_image_to_window(data->mlx, data->window, data->e[5].img, (xedni * 32), (index * 32));
				else
					mlx_put_image_to_window(data->mlx, data->window, data->e[f % 5].img, (xedni * 32), (index * 32));

			}
			else if (data->mmap[index][xedni] == 'M')
			{
				data->u[index][xedni].x = index;
				data->u[index][xedni].y = xedni;
		//		tnuoc = sl_checkposition_compair(data, data->u[count]);
				if (data->wk <= 5 && data->u[index][xedni].mv != 4)
				{
					sl_patroling_animate(data, index, xedni, 1);
				}
				else
				{
				//	printf("data->u[%d][%d].x = %d, y =%d, pf = %d\n", index, xedni, data->u[index][xedni].x, data->u[index][xedni].y, data->u[index][xedni].pf);
					mlx_put_image_to_window(data->mlx, data->window, data->m[data->u[index][xedni].pf + f].img, (xedni * 32), (index * 32));
					//mlx_put_image_to_window(data->mlx, data->window, data->m[data->u[index][xedni].pf + f].img, (xedni * 32), (index * 32));
				}
				data->u[index][xedni].k = 0;
				count++;
			}
			xedni++;
		}
		index++;
	}
	// if (data->wk == 2 && sl_checkending_player(data, 1) == 1)
	// 	printf("WIN SAME PLACE WITH EXIT\n");
//	 if (data->wk == 1 && data->end == 0 && sl_checkending(data, 3) == 3)
//	 	printf("DEAD IN SAME POSITION WITH A  MONSTER\n");
	if (data->wk == 1 && data->end == 0 && sl_checkending(data, 1) == 1)
		printf("YOU WIN GO OUT\n");
	if (data->wk <= 5 && data->end != 0 || data->end == 1)
			sl_ending_screen(data, f);
	data->wk += 1;
	

//	return (map);
}

void	sl_check_collectible(t_data *data, int key)
{
	int index;
	int xedni;

	index = 0;
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

int	sl_walkswap(t_data *data, int mode)
{
	char	tmp;

	if (mode == KEY_W && data->map[data->x - 1][data->y] != '1' && data->map[data->x - 1][data->y] != 'E')/* up */
	{	
		sl_check_collectible(data, mode);
//		if (data->map[data->x - 1][data->y] == 'C')
//			data->map[data->x - 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x - 1][data->y];
		data->map[data->x - 1][data->y] = tmp;
		data->key = KEY_W;
		data->wk = 1;
	}
	else if (mode == KEY_A && data->map[data->x][data->y - 1] != '1' && data->map[data->x][data->y - 1] != 'E')/* left */
	{
		sl_check_collectible(data, mode);
//		if (data->map[data->x][data->y -1] == 'C')
//			data->map[data->x][data->y -1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y -1];
		data->map[data->x][data->y - 1] = tmp;
		data->key = KEY_A;
		data->wk = 1;
	}
	else if (mode == KEY_S && data->map[data->x + 1][data->y] != '1' && data->map[data->x + 1][data->y] != 'E')/* down */
	{
		sl_check_collectible(data, mode);
//		if (data->map[data->x + 1][data->y] == 'C')
//			data->map[data->x + 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x + 1][data->y];
		data->map[data->x + 1][data->y] = tmp;
		data->key = KEY_S;
		data->wk = 1;
	}
	else if (mode == KEY_D && data->map[data->x][data->y + 1] != '1' && data->map[data->x][data->y + 1] != 'E')/* right */
	{
		sl_check_collectible(data, mode);
//		if (data->map[data->x][data->y + 1] == 'C')
//			data->map[data->x][data->y + 1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y + 1];
		data->map[data->x][data->y + 1] = tmp;
		data->key = KEY_D;
		data->wk = 1;
	}
	return (1);
}

int	sl_mon_patrolswap(t_data *data)
{
	char	tmp;
	int		index;
	int		xedni;
	int		fin;

	fin = 1;
	index = 0;
	srand(time(0));
	while (index < sl_checklen(data->mmap, NULL, 1))//(data->u[index] == NULL)//
	{
		xedni = 0;
		while(xedni < sl_checklen(NULL, data->mmap[index], 2))
		{
			if (data->mmap[index][xedni] == 'M' && data->u[index][xedni].k != 1)
			{
				fin = 0;
				data->u[index][xedni].mv = rand() % 5;
				if (data->u[index][xedni].mv == 0 && data->mmap[data->u[index][xedni].x - 1][data->u[index][xedni].y] != '1' && data->mmap[data->u[index][xedni].x - 1][data->u[index][xedni].y] != 'M' && data->mmap[data->u[index][xedni].x - 1][data->u[index][xedni].y] != 'E'  && data->u[index][xedni].k == 0)
				{
					tmp = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y] = data->mmap[data->u[index][xedni].x - 1][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x - 1][data->u[index][xedni].y] = tmp;
					data->u[data->u[index][xedni].x - 1][data->u[index][xedni].y].pf = data->u[index][xedni].pf;
					data->u[data->u[index][xedni].x - 1][data->u[index][xedni].y].mv = data->u[index][xedni].mv;
					data->u[data->u[index][xedni].x - 1][data->u[index][xedni].y].k = 1;
					fin = 1;
				}
				else if (data->u[index][xedni].mv == 1 && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y - 1] != '1' && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y - 1] != 'M' && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y - 1] != 'E' && data->u[index][xedni].k == 0)
				{
					tmp = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y] = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y - 1];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y - 1] = tmp;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y - 1].pf = 10;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y - 1].mv = data->u[index][xedni].mv;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y - 1].k = 1;
					fin = 1;
				}
				else if (data->u[index][xedni].mv == 2 && data->mmap[data->u[index][xedni].x + 1][data->u[index][xedni].y] != '1' && data->mmap[data->u[index][xedni].x + 1][data->u[index][xedni].y] != 'M' && data->mmap[data->u[index][xedni].x + 1][data->u[index][xedni].y] != 'E' && data->u[index][xedni].k == 0)
				{
					tmp = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y] = data->mmap[data->u[index][xedni].x + 1][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x + 1][data->u[index][xedni].y] = tmp;
					data->u[data->u[index][xedni].x + 1][data->u[index][xedni].y].pf = data->u[index][xedni].pf;
					data->u[data->u[index][xedni].x + 1][data->u[index][xedni].y].mv = data->u[index][xedni].mv;
					data->u[data->u[index][xedni].x + 1][data->u[index][xedni].y].k = 1;
					fin = 1;
				}
				else if (data->u[index][xedni].mv == 3 && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y + 1] != '1' && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y + 1] != 'M' && data->mmap[data->u[index][xedni].x][data->u[index][xedni].y + 1] != 'E' && data->u[index][xedni].k == 0)
				{
					tmp = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y] = data->mmap[data->u[index][xedni].x][data->u[index][xedni].y + 1];
					data->mmap[data->u[index][xedni].x][data->u[index][xedni].y + 1] = tmp;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y + 1].pf = 0;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y + 1].mv = data->u[index][xedni].mv;
					data->u[data->u[index][xedni].x][data->u[index][xedni].y + 1].k = 1;
					fin = 1;
				}
				else if (data->u[index][xedni].mv == 4 && data->u[index][xedni].k == 0)
					fin = 1;
			}
			if (fin == 1)
				xedni++;
		}
		index++;
	}
/*	while (index < sl_checkcompair(data->mmap, NULL, 'M', 1))//(data->u[index] == NULL)//
	{
		fin = 0;
		data->u[index].mv = rand() % 5;
		if (data->u[index].mv == 0 && data->mmap[data->u[index].x - 1][data->u[index].y] != '1' && data->mmap[data->u[index].x - 1][data->u[index].y] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x - 1][data->u[index].y];
			data->mmap[data->u[index].x - 1][data->u[index].y] = tmp;
			fin = 1;
		}
		else if (data->u[index].mv == 1 && data->mmap[data->u[index].x][data->u[index].y - 1] != '1' && data->mmap[data->u[index].x][data->u[index].y - 1] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x][data->u[index].y - 1];
			data->mmap[data->u[index].x][data->u[index].y - 1] = tmp;
			data->u[index].pf = 10;
			fin = 1;

		}
		else if (data->u[index].mv == 2 && data->mmap[data->u[index].x + 1][data->u[index].y] != '1' && data->mmap[data->u[index].x + 1][data->u[index].y] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x + 1][data->u[index].y];
			data->mmap[data->u[index].x + 1][data->u[index].y] = tmp;
			fin = 1;
		}
		else if (data->u[index].mv == 3 && data->mmap[data->u[index].x][data->u[index].y + 1] != '1' && data->mmap[data->u[index].x][data->u[index].y + 1] != 'M')
		{
			tmp = data->mmap[data->u[index].x][data->u[index].y];
			data->mmap[data->u[index].x][data->u[index].y] = data->mmap[data->u[index].x][data->u[index].y + 1];
			data->mmap[data->u[index].x][data->u[index].y + 1] = tmp;
			data->u[index].pf = 0;
			fin = 1;

		}
		else if (data->u[index].mv == 4)
			fin = 1;
		if (fin == 1)
			index++;
	}*/
	return (1);
}

int	sl_keyinput(int keycode, t_data *data)
{
	static int	count = 0;

	if (keycode == KEY_A && data->y > 0 && data->wk > 5 && data->end == 0 &&  data->map[data->x][data->y - 1] != 'E' && data->map[data->x][data->y - 1] != '1')// || keycode == KEY_A)
	{
		count += sl_walkswap(data, KEY_A);
		sl_mon_patrolswap(data);
		data->pf = 10;
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_S && data->x < sl_checklen(data->map, NULL, 1) - 1 && data->wk > 5 && data->end ==0 && data->map[data->x + 1][data->y] != 'E' && data->map[data->x + 1][data->y] != '1')//|| keycode == KEY_S)
	{
		count += sl_walkswap(data, KEY_S);
		sl_mon_patrolswap(data);
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_D && data->y < sl_checklen(NULL, data->map[0], 2) - 1 && data->wk > 5 && data->end == 0 && data->map[data->x][data->y + 1] != 'E' && data->map[data->x][data->y + 1] != '1')//|| keycode == KEY_D)
	{
		count += sl_walkswap(data, KEY_D);
		sl_mon_patrolswap(data);
		data->pf = 0;
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_W && data->x > 0 && data->wk > 5 && data->end == 0 && data->map[data->x - 1][data->y] != 'E' && data->map[data->x - 1][data->y] != '1')// || keycode == KEY_W)
	{ 
		count += sl_walkswap(data, KEY_W);
		sl_mon_patrolswap(data);
		printf("movement count == %d\n", count);
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		// destroy images //
	//	twostarstools(data->map, 0);
		free(data);
		printf("END FUNCTION\n");
		exit(0);
	}
//	twostarstools((void **)data->map, 1);
//	twostarstools((void **)data->mmap, 1);
	return (0);
}

int	sl_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
//	twostarstools(data->map, 0);
	free(data);
	exit(0);
	return (0);
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
/*	if (count >= 11109)
		count = 0;
	if (count % 1111 == 0)
	{
		sl_map_generate(data, count / 1111);
	}
	count = count + 1;
*/	return (0);
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
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (0);
	data->wk = 6;
	data->map = sl_read_map(argv);
//	sl_checkmap_misconfig(data->map);
	twostarstools((void *)data->map, 1);
	data->mmap = sl_make_mmap(data->map);
	twostarstools((void *)data->map, 1);
	data->map = sl_make_map(data->map);
	twostarstools((void *)data->mmap, 1);
	

	// temporary //
	data->x = 1;
	data->y = 1;


	printf("count M = %d\n", sl_checkcompair(data->mmap, NULL, 'M', 1));
	printf("map len = %d\n", sl_checklen(data->map, NULL, 1));
//	data->u = (t_char**)malloc(sizeof(t_char*) + sl_checkcompair(data->mmap, NULL, 'M', 1));
	data->u = (t_char**)ft_calloc(sizeof(t_char*), sl_checklen(data->mmap, NULL, 1));
	if (data->u == NULL)
	{
		//free another things//
		return (0);
	}
	int index = 0;
	while (index < sl_checklen(data->mmap, NULL, 1))
	{
		printf("mmap len = %d\n", sl_checklen(NULL, data->mmap[index], 2));
		data->u[index] = (t_char*)ft_calloc(sizeof(t_char), sl_checklen(NULL, data->mmap[index], 2));
		if (data->u[index] == NULL)
		{
			//free another things//
			return(0);
		}
		index++;
	}
	






	int width = 32 * sl_checklen(NULL, data->map[0], 2);
	int height = 32 * sl_checklen(data->map, NULL, 1);
	
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, width, height, "so_long");
	mlx_hook(data->window, 17, 0, sl_close, data);
	mlx_hook(data->window, 2, 1L<<2,  sl_p_moving, data);
//	mlx_hook(data->window, 3, 1L<<1,  sl_keyinput, data);
	mlx_key_hook(data->window, sl_keyinput, data);
	sl_map_generate(data, 0);


	mlx_loop_hook(data->mlx, sl_animating, data);
	

	mlx_loop(data->mlx);
	twostarstools((void *)data->map, 0);
	twostarstools((void *)data->mmap, 0);
	twostarstools((void *)data->u, 0);
	free(data);
	return (0);
}
