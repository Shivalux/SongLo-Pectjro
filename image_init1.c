/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:47:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:47:58 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_imageinit_one(t_data *data)
{
	data->w[0].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/1/1.xpm", &data->w[0].wid, &data->w[0].hei);
	data->s[0].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/0/01.xpm", &data->s[0].wid, &data->s[0].hei);
	data->p[0].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P1.xpm", &data->p[0].wid, &data->p[0].hei);
	data->p[1].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P2.xpm", &data->p[1].wid, &data->p[1].hei);
	data->p[2].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P3.xpm", &data->p[2].wid, &data->p[2].hei);
	data->p[3].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P4.xpm", &data->p[3].wid, &data->p[3].hei);
	data->p[4].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P5.xpm", &data->p[4].wid, &data->p[4].hei);
	data->p[5].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P6.xpm", &data->p[5].wid, &data->p[5].hei);
	data->p[6].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P7.xpm", &data->p[6].wid, &data->p[6].hei);
	data->p[7].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P8.xpm", &data->p[7].wid, &data->p[7].hei);
	data->p[8].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P9.xpm", &data->p[8].wid, &data->p[8].hei);
	data->p[9].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P0.xpm", &data->p[9].wid, &data->p[9].hei);
}

void	sl_imageinit_two(t_data *data)
{
	data->p[10].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb1.xpm", &data->p[10].wid, &data->p[10].hei);
	data->p[11].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb2.xpm", &data->p[11].wid, &data->p[11].hei);
	data->p[12].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb3.xpm", &data->p[12].wid, &data->p[12].hei);
	data->p[13].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb4.xpm", &data->p[13].wid, &data->p[13].hei);
	data->p[14].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb5.xpm", &data->p[14].wid, &data->p[14].hei);
	data->p[15].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb6.xpm", &data->p[15].wid, &data->p[15].hei);
	data->p[16].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb7.xpm", &data->p[16].wid, &data->p[16].hei);
	data->p[17].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb8.xpm", &data->p[17].wid, &data->p[17].hei);
	data->p[18].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb9.xpm", &data->p[18].wid, &data->p[18].hei);
	data->p[19].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pb0.xpm", &data->p[19].wid, &data->p[19].hei);
	data->p[20].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pr1.xpm", &data->p[20].wid, &data->p[20].hei);
	data->p[21].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pr2.xpm", &data->p[21].wid, &data->p[21].hei);
}

void	sl_imageinit_three(t_data *data)
{
	data->p[22].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pr3.xpm", &data->p[22].wid, &data->p[22].hei);
	data->p[23].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pr4.xpm", &data->p[23].wid, &data->p[23].hei);
	data->p[24].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pr5.xpm", &data->p[24].wid, &data->p[24].hei);
	data->p[25].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbr1.xpm", &data->p[25].wid, &data->p[25].hei);
	data->p[26].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbr2.xpm", &data->p[26].wid, &data->p[26].hei);
	data->p[27].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbr3.xpm", &data->p[27].wid, &data->p[27].hei);
	data->p[28].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbr4.xpm", &data->p[28].wid, &data->p[28].hei);
	data->p[29].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbr5.xpm", &data->p[29].wid, &data->p[29].hei);
	data->p[30].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pd1.xpm", &data->p[30].wid, &data->p[30].hei);
	data->p[31].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pd2.xpm", &data->p[31].wid, &data->p[31].hei);
	data->p[32].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pd3.xpm", &data->p[32].wid, &data->p[32].hei);
	data->p[33].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pd4.xpm", &data->p[33].wid, &data->p[33].hei);
}

void	sl_imageinit_four(t_data *data)
{
	data->p[34].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pd5.xpm", &data->p[34].wid, &data->p[34].hei);
	data->p[35].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbd1.xpm", &data->p[35].wid, &data->p[35].hei);
	data->p[36].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbd2.xpm", &data->p[36].wid, &data->p[36].hei);
	data->p[37].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbd3.xpm", &data->p[37].wid, &data->p[37].hei);
	data->p[38].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbd4.xpm", &data->p[38].wid, &data->p[38].hei);
	data->p[39].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pbd5.xpm", &data->p[39].wid, &data->p[39].hei);
	data->p[40].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pw4.xpm", &data->p[40].wid, &data->p[40].hei);
	data->p[41].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pw2.xpm", &data->p[41].wid, &data->p[41].hei);
	data->p[42].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/Pw3.xpm", &data->p[42].wid, &data->p[42].hei);
	data->p[43].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P7.xpm", &data->p[43].wid, &data->p[43].hei);
	data->p[44].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/P/P8.xpm", &data->p[44].wid, &data->p[44].hei);
	data->c[0].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C1.xpm", &data->c[0].wid, &data->c[0].hei);
}

void	sl_imageinit_five(t_data *data)
{
	data->c[1].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C2.xpm", &data->c[1].wid, &data->c[1].hei);
	data->c[2].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C3.xpm", &data->c[2].wid, &data->c[2].hei);
	data->c[3].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C4.xpm", &data->c[3].wid, &data->c[3].hei);
	data->c[4].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C5.xpm", &data->c[4].wid, &data->c[4].hei);
	data->c[5].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C6.xpm", &data->c[5].wid, &data->c[5].hei);
	data->c[6].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C7.xpm", &data->c[6].wid, &data->c[6].hei);
	data->c[7].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C8.xpm", &data->c[7].wid, &data->c[7].hei);
	data->c[8].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C9.xpm", &data->c[8].wid, &data->c[8].hei);
	data->c[9].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/C/C5.xpm", &data->c[9].wid, &data->c[9].hei);
	data->e[0].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/E/E1.xpm", &data->e[0].wid, &data->e[0].hei);
	data->e[1].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/E/E2.xpm", &data->e[1].wid, &data->e[1].hei);
	data->e[2].img = mlx_xpm_file_to_image(data->mlx, \
		"./images/E/E3.xpm", &data->e[2].wid, &data->e[2].hei);
}
