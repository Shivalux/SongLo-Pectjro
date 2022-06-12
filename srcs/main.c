/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:28:51 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/12 18:31:11 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init(mlx);
	window = mlx_new_window(mlx, 1000, 1000, "Hello World!");
	mlx_loop(mlx);

	return (0);
}

