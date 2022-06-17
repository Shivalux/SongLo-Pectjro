#include "./mlx/mlx.h"
#include <stdio.h>
#include "so_long.h"

int	ft_input(int key, void *param)
{
	printf("key = %d\n", key);
	return (0);
}

int	main (void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "test_d");
	mlx_key_hook(window, ft_input, NULL);
	mlx_loop(mlx);
	return (0);
}

