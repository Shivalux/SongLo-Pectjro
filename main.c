/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:33:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/20 04:10:25 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"

int	sl_checkcompair(char *str, char c)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (0);
	while (str[index] != '\0')
	{	
		if (str[index] == c)
			return (1);
		index++;
	}
	return (0);
}

void	sl_map_generate(t_data *data)
{
	t_file	img1;
	t_file	img2;
	t_file	img3;
	t_file	img4;
	t_file	img5;

	
	int index = 0;
	img1.img = mlx_xpm_file_to_image(data->mlx, "./images/test1.xpm", &img1.wid, &img1.hei);
	img2.img = mlx_xpm_file_to_image(data->mlx, "./images/test2.xpm", &img2.wid, &img2.hei); 
	img3.img = mlx_xpm_file_to_image(data->mlx, "./images/test3.xpm", &img3.wid, &img3.hei);
	img4.img = mlx_xpm_file_to_image(data->mlx, "./images/test4.xpm", &img4.wid, &img4.hei);
	img5.img = mlx_xpm_file_to_image(data->mlx, "./images/test5.xpm", &img5.wid, &img5.hei);
	while (data->map[index] != NULL)
	{
		int xedni = 0;
		while (data->map[index][xedni] != '\0')
		{
			if (data->map[index][xedni] == '1')
				mlx_put_image_to_window(data->mlx, data->window, img1.img, (xedni * 64), (index * 64));
			else if (data->map[index][xedni] == '0')
				mlx_put_image_to_window(data->mlx, data->window, img2.img, (xedni * 64), (index * 64));
			else if (sl_checkcompair("CEP", data->map[index][xedni]) != 0)
			{
				mlx_put_image_to_window(data->mlx, data->window, img2.img, (xedni * 64), (index * 64));
				if (data->map[index][xedni] == 'C')
					mlx_put_image_to_window(data->mlx, data->window, img4.img, (xedni * 64), (index * 64));
				else if (data->map[index][xedni] == 'E')
					mlx_put_image_to_window(data->mlx, data->window, img5.img, (xedni * 64), (index * 64));
				else if (data->map[index][xedni] == 'P')
				{
					mlx_put_image_to_window(data->mlx, data->window, img3.img, (xedni * 64), (index * 64));
					data->x = index;
					data->y = xedni;
				}
			}
			xedni++;
		}
		index++;
	}
//	return (map);
}

void sl_walkswap(t_data *data, int mode)
{
	char	tmp;

	if (mode == KEY_UP && data->map[data->x - 1][data->y] != '1')/* up */
	{	
		if (data->map[data->x - 1][data->y] == 'C')
			data->map[data->x - 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x - 1][data->y];
		data->map[data->x - 1][data->y] = tmp;
	}
	else if (mode == KEY_LEFT && data->map[data->x][data->y - 1] != '1')/* left */
	{
		if (data->map[data->x][data->y -1] == 'C')
			data->map[data->x][data->y -1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y -1];
		data->map[data->x][data->y - 1] = tmp;
	}
	else if (mode == KEY_DOWN && data->map[data->x + 1][data->y] != '1')/* down */
	{
		if (data->map[data->x + 1][data->y] == 'C')
			data->map[data->x + 1][data->y] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x + 1][data->y];
		data->map[data->x + 1][data->y] = tmp;
	}
	else if (mode == KEY_RIGHT && data->map[data->x][data->y + 1] != '1')/* right */
	{
		if (data->map[data->x][data->y + 1] == 'C')
			data->map[data->x][data->y + 1] = '0';
		tmp = data->map[data->x][data->y];
		data->map[data->x][data->y] = data->map[data->x][data->y + 1];
		data->map[data->x][data->y + 1] = tmp;
	}
}

int	sl_keyinput(int keycode, t_data *data)
{
	static int	count = 0;

	if (keycode == KEY_LEFT && data->y > 0)// || keycode == KEY_A)
		sl_walkswap(data, KEY_LEFT);
	else if (keycode == KEY_DOWN && data->x < sl_checklen(data->map, NULL, 1) - 1)//|| keycode == KEY_S)
		sl_walkswap(data, KEY_DOWN);
	else if (keycode == KEY_RIGHT && data->y < sl_checklen(NULL, data->map[0], 2) - 1)//|| keycode == KEY_D)
		sl_walkswap(data, KEY_RIGHT);
	else if (keycode == KEY_UP && data->x > 0)// || keycode == KEY_W)
		sl_walkswap(data, KEY_UP);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		// destroy images //
		twostarstools(data->map, 0);
		free(data);
		printf("END FUNCTION\n");
		exit(0);
	}
	sl_map_generate(data);
	printf("keycode == %d, count = %d\n", keycode, count);
	count++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	if (argc != 2)
	{	
		write(1, "WRONG ARGUMENT\n", 15);
		return (0);
	}
	data->map = sl_read_map(argv);
	data->mlx = mlx_init();

	
	int width = 64 * sl_checklen(NULL, data->map[0], 2);
	int height = 64 * sl_checklen(data->map, NULL, 1);
	

	data->window = mlx_new_window(data->mlx, width, height, "so_long");
	sl_map_generate(data);
	mlx_key_hook(data->window, sl_keyinput, data);
	



	

	twostarstools(data->map, 1);
	mlx_loop(data->mlx);
	twostarstools(data->map, 0);
	free(data);
	return (0);
}
