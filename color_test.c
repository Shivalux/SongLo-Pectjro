/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:16:22 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/14 23:05:58 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"
#include <stdio.h>


	// create colour wiht bit with bit shifting //
int	create_colour(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_colour(int colour, int mode)
{
	if (mode == 1)
		return ((colour >> 24) & 0xFF);
	else if (mode == 2)
		return ((colour >> 16) & 0xFF);
	else if (mode == 3)
		return ((colour >> 8) & 0xFF);
	else
		return (colour & 0xFF);

}

int	create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_color(int colour, int mode)
{
	if (mode == 1)
		return (((unsigned char *)&colour)[3]);
	else if (mode == 2)
		return (((unsigned char *)&colour)[2]);
	else if (mode == 3)
		return (((unsigned char *)&colour)[1]);
	else
		return (((unsigned char *)&colour)[0]);
}
/*
int	main(void)
{
	int	t = 0;
	int r = 255;
	int g = 255;
	int b = 255;
	int	colour;
	int	red;


	colour = create_colour(t, r, g, b);
//	g = g << 8;
//	t = t << 24;
	printf("green = %d, %x\n", GREEN, GREEN);
	printf("colour = %#x | t = %d, r = %d, g = %d, b =%d\n", colour, t, r, g, b);
	red = get_colour(colour, 2);
	int	color;
	color = get_colour(0xFF0000, 2);
	printf("red = %d, %x || color = %d, %x\n", red, red, color ,color);
	return (0);
}*/
