#include "so_long.h"

void    sl_imageinit_six(t_data *data)
{
	data->e[3].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/E/E4.xpm", &data->e[3].wid, &data->e[3].hei);
	data->e[4].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/E/E5.xpm", &data->e[4].wid, &data->e[4].hei);
	data->e[5].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/E/EE7.xpm", &data->e[5].wid, &data->e[5].hei);
	data->m[0].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M9.xpm", &data->m[0].wid, &data->m[0].hei);
	data->m[1].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M0.xpm", &data->m[1].wid, &data->m[1].hei);
	data->m[2].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M1.xpm", &data->m[2].wid, &data->m[2].hei);
	data->m[3].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M2.xpm", &data->m[3].wid, &data->m[3].hei);
	data->m[4].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M3.xpm", &data->m[4].wid, &data->m[4].hei);
	data->m[5].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M4.xpm", &data->m[5].wid, &data->m[5].hei);
	data->m[6].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M5.xpm", &data->m[6].wid, &data->m[6].hei);
	data->m[7].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M6.xpm", &data->m[7].wid, &data->m[7].hei);
	data->m[8].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M7.xpm", &data->m[8].wid, &data->m[8].hei);
}

void    sl_imageinit_seven(t_data *data)
{
	data->m[9].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/M8.xpm", &data->m[9].wid, &data->m[9].hei);
	data->m[10].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb1.xpm", &data->m[10].wid, &data->m[10].hei);
	data->m[11].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb2.xpm", &data->m[11].wid, &data->m[11].hei);
	data->m[12].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb3.xpm", &data->m[12].wid, &data->m[12].hei);
	data->m[13].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb4.xpm", &data->m[13].wid, &data->m[13].hei);
	data->m[14].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb5.xpm", &data->m[14].wid, &data->m[14].hei);
	data->m[15].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb6.xpm", &data->m[15].wid, &data->m[15].hei);
	data->m[16].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb7.xpm", &data->m[16].wid, &data->m[16].hei);
	data->m[17].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb8.xpm", &data->m[17].wid, &data->m[17].hei);
	data->m[18].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb9.xpm", &data->m[18].wid, &data->m[18].hei);
	data->m[19].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mb0.xpm", &data->m[19].wid, &data->m[19].hei);
	data->m[20].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mr1.xpm", &data->m[20].wid, &data->m[20].hei);
}

void    sl_imageinit_eight(t_data *data)
{
	data->m[21].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mr2.xpm", &data->m[21].wid, &data->m[21].hei);
	data->m[22].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mr3.xpm", &data->m[22].wid, &data->m[22].hei);
	data->m[23].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mr4.xpm", &data->m[23].wid, &data->m[23].hei);
	data->m[24].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mr5.xpm", &data->m[24].wid, &data->m[24].hei);
	data->m[25].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mbr1.xpm", &data->m[25].wid, &data->m[25].hei);
	data->m[26].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mbr2.xpm", &data->m[26].wid, &data->m[26].hei);
	data->m[27].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mbr3.xpm", &data->m[27].wid, &data->m[27].hei);
	data->m[28].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mbr4.xpm", &data->m[28].wid, &data->m[28].hei);
	data->m[29].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mbr5.xpm", &data->m[29].wid, &data->m[29].hei);
	data->m[30].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Ma1.xpm", &data->m[30].wid, &data->m[30].hei);
	data->m[31].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Ma2.xpm", &data->m[31].wid, &data->m[31].hei);
	data->m[32].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Ma3.xpm", &data->m[32].wid, &data->m[32].hei);
}

void    sl_imageinit_nine(t_data *data)
{
	data->m[33].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Ma4.xpm", &data->m[33].wid, &data->m[33].hei);
	data->m[34].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Ma5.xpm", &data->m[34].wid, &data->m[34].hei);
	data->m[35].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mba1.xpm", &data->m[35].wid, &data->m[35].hei);
	data->m[36].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mba2.xpm", &data->m[36].wid, &data->m[36].hei);
	data->m[37].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mba3.xpm", &data->m[37].wid, &data->m[37].hei);
	data->m[38].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mba4.xpm", &data->m[38].wid, &data->m[38].hei);
	data->m[39].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/M/Mba5.xpm", &data->m[39].wid, &data->m[39].hei);
	data->n[0].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N0.xpm", &data->n[0].wid, &data->n[0].hei);
	data->n[1].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N1.xpm", &data->n[1].wid, &data->n[1].hei);
	data->n[2].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N2.xpm", &data->n[2].wid, &data->n[2].hei);
	data->n[3].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N3.xpm", &data->n[3].wid, &data->n[3].hei);
	data->n[4].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N4.xpm", &data->n[4].wid, &data->n[4].hei);
}

void    sl_imageinit_ten(t_data *data)
{
	data->n[5].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N5.xpm", &data->n[5].wid, &data->n[5].hei);
	data->n[6].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N6.xpm", &data->n[6].wid, &data->n[6].hei);
	data->n[7].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N7.xpm", &data->n[7].wid, &data->n[7].hei);
	data->n[8].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N8.xpm", &data->n[8].wid, &data->n[8].hei);
	data->n[9].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/N9.xpm", &data->n[9].wid, &data->n[9].hei);
	data->n[10].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/Ne1.xpm", &data->n[10].wid, &data->n[10].hei);
	data->n[11].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/Ne2.xpm", &data->n[11].wid, &data->n[11].hei);
	data->n[12].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/Ne3.xpm", &data->n[12].wid, &data->n[12].hei);
	data->n[13].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/Ne4.xpm", &data->n[13].wid, &data->n[13].hei);
	data->n[14].img = mlx_xpm_file_to_image(data->mlx,\
                "./images/N/Ne5.xpm", &data->n[14].wid, &data->n[14].hei);
}