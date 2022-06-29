/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:09:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 00:34:17 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**sl_read_map(char **argv)
{
	char	**result;
	char	*line;
	int		i;
	int		fd;

	result = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (0 < 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		result = sl_join_map(result, line);
		if (result == NULL)
			break ;
	}
	close(fd);
	return (result);
}

char	**sl_make_mmap(t_data *data)
{
	char	**result;
	int		i;
	int		xedni;

	i = 0;
	result = (char **)ft_calloc(8, sl_checklen(data->map, NULL, 1) + 1);
	if (result == NULL)
		sl_free_for_all(data, 1);
	while (data->map[i] != NULL)
	{
		xedni = 0;
		result[i] = ft_calloc(1, sl_checklen(NULL, data->map[i], 2) + 1);
		if (result[i] == NULL)
			sl_free_for_all(data, 1);
		while (data->map[i][xedni] != '\0')
		{
			if (sl_checkcompair (NULL, "PC", data->map[i][xedni], 2) != 0)
				result[i][xedni] = '0';
			else
				result[i][xedni] = data->map[i][xedni];
			xedni++;
		}
		i++;
	}
	return (result);
}

void	sl_make_map(t_data *data, int i)
{
	int		xedni;
	char	*extra;

	while (data->map[i] != NULL)
	{
		xedni = 0;
		while (data->map[i][xedni] != '\0')
		{
			if (data->map[i][xedni] == 'M')
				data->map[i][xedni] = '0';
			xedni++;
		}
		i++;
	}
	extra = (char *)ft_calloc(1, sl_checklen(NULL, data->map[0], 2) + 1);
	if (extra == NULL)
	{
		sl_free_for_all(data, 0);
	}
	while (--xedni >= 0)
		extra[xedni] = '1';
	data->map = sl_join_map(data->map, extra);
}

void	sl_make_ummap(t_data *data)
{
	int	i;

	i = 0;
	data->u = (t_char **)ft_calloc(sizeof(t_char *), \
		sl_checklen(data->mmap, NULL, 1));
	if (data->u == NULL)
	{
		sl_free_for_all(data, 0);
	}
	while (i < sl_checklen(data->mmap, NULL, 1))
	{
		data->u[i] = (t_char *)ft_calloc(sizeof(t_char), \
			sl_checklen(NULL, data->mmap[i], 2));
		if (data->u[i] == NULL)
		{
			sl_free_for_all(data, 0);
		}
		i++;
	}
}
