/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:04:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/15 13:27:09 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_pix
{
	void	*img;
	char	*path;
	int		wid;
	int		hei;
}	t_pix;

int main(void)
{
	t_data	*data;
	t_pix	wall;

	data = (t_data *)malloc(sizeof(t_data) + 1);
	wall.path = "./frogsprite.xpm";
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1000, 1000, "image testing");
	wall.img = mlx_xpm_file_to_image(data->mlx, wall.path ,&wall.wid, &wall.hei);
	printf("hei = %d, wid = %d\n", wall.hei, wall.wid);
	wall.wid = 200;
	mlx_put_image_to_window(data->mlx, data->window, wall.img, 0, 0);	
	mlx_loop(data->mlx);
	return (0);
}
