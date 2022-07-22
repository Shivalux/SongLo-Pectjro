/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:03:58 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 01:17:00 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(int size, int count)
{
	void	*result;
	int		i;
	char	*str;

	i = 0;
	result = malloc(size * count);
	if (result == NULL)
		return (0);
	str = result;
	while (i < (size * count))
	{
		str[i] = 0;
		i++;
	}
	return (result);
}

void	sl_free_for_all(t_data *data, int mode)
{
	int	i;

	i = 0;
	if (mode == 2)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		sl_destroy_images(data);
	}
	if (data->u != NULL)
	{
		while (i < sl_checklen(data->mmap, NULL, 1))
		{
			free(data->u[i++]);
		}
		free(data->u);
	}
	if (data->map != NULL)
		sl_twostars_tools(data->map, 2);
	if (data->mmap != NULL)
		sl_twostars_tools(data->mmap, 2);
	free(data);
	exit (0);
}

void	sl_destroy_images(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->s[0].img);
	mlx_destroy_image(data->mlx, data->w[0].img);
	while (i < 10)
		mlx_destroy_image(data->mlx, data->c[i++].img);
	i = 0;
	while (i < 45)
		mlx_destroy_image(data->mlx, data->p[i++].img);
	i = 0;
	while (i < 6)
		mlx_destroy_image(data->mlx, data->e[i++].img);
	i = 0;
	while (i < 40)
		mlx_destroy_image(data->mlx, data->m[i++].img);
	i = 0;
	while (i < 15)
		mlx_destroy_image(data->mlx, data->n[i++].img);
}

void	sl_imageinit(t_data *data)
{
	sl_imageinit_one(data);
	sl_imageinit_two(data);
	sl_imageinit_three(data);
	sl_imageinit_four(data);
	sl_imageinit_five(data);
	sl_imageinit_six(data);
	sl_imageinit_seven(data);
	sl_imageinit_eight(data);
	sl_imageinit_nine(data);
	sl_imageinit_ten(data);
}

void	sl_print_error(void)
{
	ft_printf("======================================================\n");
	ft_printf("  ERROR: WRONG ARGUMENT :(\n");
	ft_printf("  $> ./so_long [path of the map]\n");
	ft_printf("  (example) $> ./so_long ./maps/simple_valid_map.ber\n");
	ft_printf("======================================================\n");
	ft_printf(" => ./maps/simple_valid_map.ber\n");
	ft_printf(" => ./maps/minimal_map.ber\n");
	ft_printf(" ==> ./maps/bonus_easy.ber\n");
	ft_printf(" ==> ./maps/bonus_hard.ber\n");
	ft_printf(" ===> ./maps/error_map_missing_wall.ber\n");
	ft_printf(" ===> ./maps/error_map_no_c.ber\n");
	ft_printf(" ===> ./maps/error_map_no_e.ber\n");
	ft_printf(" ===> ./maps/error_map_no_p.ber\n");
	ft_printf(" ===> ./maps/error_map_not_rectangle.ber\n");
	exit(0);
}
