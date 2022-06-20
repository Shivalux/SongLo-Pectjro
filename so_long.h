/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:24:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/21 02:08:20 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
//# include "libft/libft.h"
//# include "libftprintf/libftprintf.h"
//# include "getnextline/gitnextline.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define FPS 60
# define WINDOW_HEIGHT 300
# define WINDOW_WIDTH 600
# define RED 0xFF0000
# define GREEN 0xFF00
# define BULE 0xFF
# define WHITE 0xFFFFFF

/* key define */
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 19
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_SPACE 49
# define KEY_ESC 53

typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
}   t_rect;
 
typedef struct s_img
{
	void    *img;
	char    *addr;
	int     bpp;
	int     line_length;
	int     ending;
}   t_img;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_file
{
	void	*img;
	char	*path;
	int		wid;
	int		hei;
}	t_file;

typedef struct s_data
{
	void    *mlx;
	void    *window;
	char	**map;
	int		x;
	int		y;
	t_file	c[10];
}   t_data;

// main functions //
char	**sl_read_map(char **arg);


// utility function
int		sl_checklen(char **rts, char *str, int mode);
void	twostarstools(char **str, int mode);


int	create_colour(int t, int r, int g, int b);
int	get_colour(int colour, int mode);
int create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char get_color(int colour, int mode);

#endif
