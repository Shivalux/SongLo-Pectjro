/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:33:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/19 01:13:01 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	char **map;

	if (argc != 2)
	{	
		write(1, "WRONG ARGUMENT\n", 15);
		return (0);
	}
	map = sl_read_map(argv);
	

	twostarstools(map, 1);
	twostarstools(map, 0);
	return (0);
}