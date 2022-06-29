/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:24:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 00:50:13 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libftprintf/libftprintf.h"
# include "./getnextline/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

typedef struct s_file
{
	void	*img;
	char	*path;
	int		wid;
	int		hei;
}	t_file;

typedef struct s_char
{
	int	k;
	int	pf;
	int	mv;
	int	kil;
	int	x;
	int	y;
}	t_char;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	char	**mmap;
	int		x;
	int		y;
	int		end;
	t_file	s[1];
	t_file	w[1];
	t_file	c[10];
	t_file	p[45];
	t_file	e[6];
	t_file	m[40];
	t_file	n[15];
	int		mc;
	int		key;
	int		pf;
	int		wk;
	t_char	i[1];
	t_char	**u;
}	t_data;

char	**sl_read_map(char **arg);
char	**sl_make_mmap(t_data *data);
void	sl_make_map(t_data *data, int i);
char	**sl_join_map(char **rts, char *str);
void	sl_checkmap_misconfig(t_data *data);
int		sl_keyinput(int keycode, t_data *data);
void	sl_key_manage(t_data *data, int keycode);
int		sl_close(t_data *data);
int		sl_animating(t_data *data);
void	sl_mon_patrolswap(t_data *data, int i, int fin, char tmp);
int		sl_checking_patroling_one(t_data *data, int i, int j, char tmp);
int		sl_checking_patroling_two(t_data *data, int i, int j, char tmp);
void	sl_check_collectible(t_data *data, int key, int i);
void	sl_swapvalue(t_data *data, int mode, char tmp);
int		sl_walkswap(t_data *data, int mode);
int		sl_check_misconfig(char **map);
void	sl_checkmap_misconfig(t_data *data);
void	sl_walking_animate(t_data *data);
void	sl_patroling_animate(t_data *data, int i, int xedni, int mode);
void	sl_patroling_animate_normal(t_data *data, int i, int xedni);
void	sl_patroling_animate_spacial(t_data *data, int i, int xedni);
char	**sl_joininfo_result(char **result, char *str, int i);
int		sl_moveinfo_result(char **rts, char **result);
void	sl_imageinit_one(t_data *data);
void	sl_imageinit_two(t_data *data);
void	sl_imageinit_three(t_data *data);
void	sl_imageinit_four(t_data *data);
void	sl_imageinit_five(t_data *data);
void	sl_imageinit_six(t_data *data);
void	sl_imageinit_seven(t_data *data);
void	sl_imageinit_eight(t_data *data);
void	sl_imageinit_nine(t_data *data);
void	sl_imageinit_ten(t_data *data);
void	sl_imageinit(t_data *data);
void	sl_destroy_images(t_data *data);
void	sl_free_for_all(t_data *data, int mode);
void	*ft_calloc(int size, int count);
void	sl_putimage_space_layer(t_data *data);
void	sl_putimage_count(t_data *data);
void	sl_putimage_mmap(t_data *data, int i, int xedni, int f);
void	sl_putimage_monster(t_data *data, int f);
void	sl_putimage_map(t_data *d, int f, int i, int j);
void	sl_putimage_map_layer(t_data *data, int f);
void	sl_map_generate(t_data *data, int f);
void	sl_ending_screen(t_data *data, int f);
int		sl_checkending(t_data *data, int mode);
void	sl_ending_one(t_data *data, int f);
void	sl_ending_two(t_data *data);
void	sl_ending_two_player(t_data *data);
void	sl_ending_two_monster(t_data *data);
void	sl_ending_three_one(t_data *data);
void	sl_ending_three_two(t_data *data);
void	sl_ending_three_two_player(t_data *data);
void	sl_ending_three_two_monster(t_data *data);
void	sl_make_ummap(t_data *data);
int		sl_checklen(char **rts, char *str, int mode);
int		sl_checkcompair(char **rts, char *str, char c, int mode);
void	sl_twostars_tools(char **str, int mode);
int		sl_count_digit(int nbr);
void	sl_print_error(void);

#endif
