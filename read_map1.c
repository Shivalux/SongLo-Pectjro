#include "so_long.h"

char	**sl_read_map(char **argv)
{
	char	**result;
	char	*line;
	int		index;
	int		fd;

	result = NULL;
	index = 0;
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

char **sl_make_mmap(char **map)
{
	char	**result;
	int		index;
	int		xedni;
	
	index = 0;
	result = (char **)ft_calloc(sizeof(char *), sl_checklen(map, NULL, 1) + 1);
	if (result == NULL)
	{
		/* free  another malloc */
		exit(0);
	}
	while (map[index] != NULL)
	{
		xedni = 0;
		result[index] = (char *)ft_calloc(sizeof(char), sl_checklen(NULL, map[index], 2) + 1);
		if (result[index] == NULL)
		{
			/* free another malloc */
			exit(0);
		}
		while (map[index][xedni] != '\0')
		{
			if (sl_checkcompair (NULL, "PC", map[index][xedni], 2) != 0)
				result[index][xedni] = '0';
			else
				result[index][xedni] = map[index][xedni];
			xedni++;
		}
		index++;
	}
	return (result);
}

char **sl_make_map(char **map)
{
	int		index;
	int		xedni;
	char	*extra;

	index = 0;
	while (map[index] != NULL)
	{
		xedni = 0;
		while (map[index][xedni] != '\0')
		{
			if (map[index][xedni] == 'M')
				map[index][xedni] = '0';
			xedni++;
		}
		index++;
	}
	extra = (char *)ft_calloc(sizeof(char), sl_checklen(NULL, map[0], 2) + 1);
	if (extra == NULL)
	{
		sl_twostars_tools(map, 0);
		return (0);
	}
	while (--xedni >= 0)
		extra[xedni] = '1';
	map = sl_join_map(map, extra);
	return (map);
}

void	sl_make_ummap(t_data *data)
{
	int index;

	index = 0;
	data->u = (t_char**)ft_calloc(sizeof(t_char*), sl_checklen(data->mmap, NULL, 1));
	if (data->u == NULL)
	{
		sl_free_for_all(data, 0);
	}
	while (index < sl_checklen(data->mmap, NULL, 1))
	{
		data->u[index] = (t_char*)ft_calloc(sizeof(t_char), sl_checklen(NULL, data->mmap[index], 2));
		if (data->u[index] == NULL)
		{
			sl_free_for_all(data, 0);
		}
		index++;
	}
}