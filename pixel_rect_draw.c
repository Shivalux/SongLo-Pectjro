/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:42:30 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/14 02:06:59 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>

#define	GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define	BLUE_PIXEL 0xFF
#define WHITE_PIXEL 0xFFFFFF

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300

typedef struct s_rect
{
	int	x;
	int y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bpp; // bits per pixrel
	int		line_length;
	int		ending;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*window;
//	char	*addr;
	t_img	img;
//	int		bit_per_pixel;
//	int		line_length;
//	int		ending;
}	t_data;



/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + i * (data->bit_per_pixel / 8)); // สมการการเข้าถึงตำแหน่งอาเรย์บนหน้าจอ
	*(unsigned int*)dst = color;
}
*/
/*
	// draw rectangle function //
int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->window == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx, data->window, j++, i, rect.color);
		i++;
	}
	return (0);
}

	// draw rectangle function //
void	render_background(t_data *data, int color)
{
	int i;
	int	j;

	if (data->window == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx, data->window, j++, i, color);
		i++;
	}
}

int	render(t_data *data)
{
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(data, (t_rect){ 100, 100, 100, 100, BLUE_PIXEL});
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

	return (0);
}
*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8; // optional
	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)pixel = color;
	while (i >= 0) //optional
	{
		if (img->ending != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >>(img->bpp - 8 -i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		i++;
	}
}

int	render(t_data *data)
{
	if (data->window == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (0);
}

int	main(void)
{
//	void	*mlx;
//	void	*window;
	t_data	*data;
	t_rect	rect;
//	t_data	img;
	int		x;
	int		y;

	data = (t_data *)malloc(sizeof(t_data) + 1);
	if (data == NULL)
		return (0);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World");
	data->img.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_length, &data->img.ending);
	render(data);

/*	rect.x = 100;
	rect.y = 100;
	rect.height = 200;
	rect.width = 200;
	rect.color = RED_PIXEL;
	render_background(data, WHITE_PIXEL);
	x = render_rect(data, rect);
*/	
//	render(data);

//	render(data);
//	img.img = mlx_new_image(mlx, 1920, 1080);
//	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.ending);
//	x = 300;
//	while (x < 901)
//		my_mlx_pixel_put(&img, x++, 300, 0x00FF0000);
//	x = 300;
//	while (x < 901)
//		my_mlx_pixel_put(&img, x++, 900, 0x0000FF00);
//	y = 300;
//	while (y < 901)
//		my_mlx_pixel_put(&img, 300, y++, 0x00FF0000);
//	y = 300;
//	while (y < 901)
//		my_mlx_pixel_put(&img, 900, y++, 0x000FF000);
//	mlx_put_image_to_window(mlx, window, img.img, 0,0);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}

