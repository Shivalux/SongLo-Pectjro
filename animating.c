#include "so_long.h"

void	sl_walking_animate(t_data *data)
{	
	if (data->end == 1)
		mlx_put_image_to_window(data->mlx, data->window, \
            data->e[5].img, data->y * 32, data->x * 32);
	else
		mlx_put_image_to_window(data->mlx, data->window, \
            data->s[0].img, data->y * 32, data->x * 32);
	if (data->key == KEY_A)
		mlx_put_image_to_window(data->mlx, data->window, \
            data->p[24 + data->wk].img, ((data->y + 1) * 32) - (6 * data->wk), data->x * 32);
	else if (data->key == KEY_S)
		mlx_put_image_to_window(data->mlx, data->window, \
            data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x - 1) * 32) + (6 * data->wk));
	else if (data->key == KEY_D)
		mlx_put_image_to_window(data->mlx, data->window, \
            data->p[19 + data->wk].img, ((data->y - 1) * 32) + (6 * data->wk), data->x * 32);
	else if (data->key == KEY_W)
		mlx_put_image_to_window(data->mlx, data->window, \
            data->p[(19 + (data->pf / 2)) + data->wk].img, data->y * 32, ((data->x + 1) * 32) - (6 * data->wk));
}

void	sl_patroling_animate(t_data *data, int index, int xedni, int mode)
{
	if (data->u[index][xedni].kil == 0 && mode == 1 || mode == 2 && data->end == 3)
	{
        sl_patroling_animate_normal(data, index, xedni);
		// if (data->u[index][xedni].mv == 1)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, ((data->u[index][xedni].y + 1) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		// else if (data->u[index][xedni].mv == 2)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x - 1) * 32) + (6 * data->wk));
		// else if (data->u[index][xedni].mv == 3)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, ((data->u[index][xedni].y - 1) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		// else if (data->u[index][xedni].mv == 0)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x + 1) * 32) - (6 * data->wk));
	}
	else if (mode == 2 && data->end == 2)
	{
        sl_patroling_animate_spacial(data, index, xedni);
		// if (data->u[index][xedni].mv == 1)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, ((data->u[index][xedni].y) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		// else if (data->u[index][xedni].mv == 2)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) + (6 * data->wk));
		// else if (data->u[index][xedni].mv == 3)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, ((data->u[index][xedni].y) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		// else if (data->u[index][xedni].mv == 0)
		// 	mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) - (6 * data->wk));
	}
}
void    sl_patroling_animate_normal(t_data *data, int index, int xedni)
{
    if (data->u[index][xedni].mv == 1)
		mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, \
            ((data->u[index][xedni].y + 1) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
	else if (data->u[index][xedni].mv == 2)
		mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, \
            data->u[index][xedni].y * 32, ((data->u[index][xedni].x - 1) * 32) + (6 * data->wk));
	else if (data->u[index][xedni].mv == 3)
		mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, \
            ((data->u[index][xedni].y - 1) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
	else if (data->u[index][xedni].mv == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, \
            data->u[index][xedni].y * 32, ((data->u[index][xedni].x + 1) * 32) - (6 * data->wk));
}

void    sl_patroling_animate_spacial(t_data *data, int index, int xedni)
{
    if (data->u[index][xedni].mv == 1)
			mlx_put_image_to_window(data->mlx, data->window, data->m[24 + data->wk].img, \
                ((data->u[index][xedni].y) * 32) - (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 2)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, \
                data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) + (6 * data->wk));
		else if (data->u[index][xedni].mv == 3)
			mlx_put_image_to_window(data->mlx, data->window, data->m[19 + data->wk].img, \
                ((data->u[index][xedni].y) * 32) + (6 * data->wk), data->u[index][xedni].x * 32);
		else if (data->u[index][xedni].mv == 0)
			mlx_put_image_to_window(data->mlx, data->window, data->m[(19 + (data->u[index][xedni].pf / 2)) + data->wk].img, \
                data->u[index][xedni].y * 32, ((data->u[index][xedni].x) * 32) - (6 * data->wk));
}