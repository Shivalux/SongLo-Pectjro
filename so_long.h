/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:24:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 01:06:53 by sharnvon         ###   ########.fr       */
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
# include <time.h>

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
# define KEY_W 13
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

typedef	struct s_char
{
	int k;
	int	pf;
	int mv;
	int	kil;
	int	x;
	int y;
}
	t_char;

typedef struct s_data
{
	void    *mlx;
	void    *window;
	char	**map;
	char	**mmap;
	int		x;
	int		y;
	int		end;
	t_file	s[1];
	t_file	w[1];
	t_file	c[10];
	t_file	p[45];
	t_file	e[10];
	t_file	m[40];
	t_file	n[15];
	int		mc;
	int		key;
	int		pf;
	int		wk;
	t_char	i[1];
	t_char	**u;
}   t_data;

// main functions //
char	**sl_read_map(char **arg);
char	**sl_make_mmap(char **map);
char	**sl_make_map(char **map);
void	sl_checkmap_misconfig(t_data *data);

// utility function
/*check length of rts/str | 1: len of **rts | 2: len of *str | 3: ln of *str*/
int		sl_checklen(char **rts, char *str, int mode);
/*finding c in rts/str | mode1: find in **rts | mode2: finding *str*/
int		sl_checkcompair(char **rts, char *str, char c, int mode);
/*tools for **str | mode1: print **str | mode2: free **str*/
void	twostarstools(void **str, int mode);


int	create_colour(int t, int r, int g, int b);
int	get_colour(int colour, int mode);
int create_color(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned char get_color(int colour, int mode);

#endif
