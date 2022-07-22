/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:06:54 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 01:36:00 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		sl_print_error();
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (0);
	data->wk = 6;
	data->x = 1;
	data->y = 1;
	data->map = sl_read_map(argv);
	sl_checkmap_misconfig(data);
	data->mmap = sl_make_mmap(data);
	sl_make_map(data, 0);
	sl_make_ummap(data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 32 * sl_checklen(NULL, \
		data->map[0], 2), 32 * sl_checklen(data->map, NULL, 1), "./so_long");
	sl_imageinit(data);
	sl_map_generate(data, 0);
	mlx_hook(data->window, 17, 0, sl_close, data);
	mlx_hook(data->window, 2, 1L << 0, sl_keyinput, data);
	mlx_loop_hook(data->mlx, sl_animating, data);
	mlx_loop(data->mlx);
	return (0);
}
