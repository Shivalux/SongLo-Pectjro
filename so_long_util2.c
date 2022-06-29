#include "so_long.h"

void	*ft_calloc(int size, int count)
{
	void	*result;
	int		index;
	char	*str;

	index = 0;
	result = malloc(size * count);
	if (result == NULL)
	return (0);
	str = result;
	while(index < (size * count))
	{
		str[index] = 0;
		index++;
	}  
	return (result);
	}

void    sl_free_for_all(t_data *data, int mode)
{
	int	index;

	index = 0;
	if (mode == 2)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_destroy_window(data->mlx, data->window);
		sl_destroy_images(data);
	}
	if (data->u != NULL)
	{
		while(index < sl_checklen(data->map, NULL, 1))
			free(data->u[index++]);
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
	int	index;

	index = 0;
	mlx_destroy_image(data->mlx, data->s[0].img);
	mlx_destroy_image(data->mlx, data->w[0].img);
	while(index < 10)
		mlx_destroy_image(data->mlx, data->c[index++].img);
	index = 0;
	while(index < 45)
		mlx_destroy_image(data->mlx, data->p[index++].img);
	index = 0;
	while(index < 6)
		mlx_destroy_image(data->mlx, data->e[index++].img);
	index = 0;
	while(index < 40)
		mlx_destroy_image(data->mlx, data->m[index++].img);
	index = 0;
	while (index < 15)
		mlx_destroy_image(data->mlx, data->n[index++].img);
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
	ft_printf(" ===> ./maps/erroe_map_not_rectangle.ber\n");
	exit(0);
}