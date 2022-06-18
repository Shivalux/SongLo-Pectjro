/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:11:46 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/19 01:12:28 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"

char	**sl_join_map(char **rts, char *str)
{
	char	**result;
	int		index;
	int		xedni;

	index = 0;
	if (str == NULL)
		return (0);
	if (rts == NULL)
		result = (char **)ft_calloc(sizeof(char *), 2);
	else
		result = (char **)ft_calloc(sizeof(char *), sl_checklen(rts, NULL, 1) + 2);
	if (result == NULL)
	{
		/* free another result that use to malloc ??*/
		exit(0);
	}
	while (rts != NULL && rts[index] != NULL)
	{
		xedni = 0;
		result[index] = (char *)ft_calloc(sizeof(char), sl_checklen(NULL, rts[index], 3) + 1);
		if (result == NULL)
		{
			/* free another result that use to malloc ??*/
			exit(0);
		}
		while (rts[index][xedni] != '\0' && rts[index][xedni] != '\n')
		{
			result[index][xedni] = rts[index][xedni];
			xedni++;
		}
		result[index][xedni] = '\0';
		index++;
	}
	result[index] = (char *)ft_calloc(sizeof(char *), sl_checklen(NULL, str, 3) + 1);
	if (result == NULL)
	{
		/* free another result that use to malloc ??*/
		exit(0);
	}
	xedni = 0;
	while (str[xedni] != '\0')
	{
		result[index][xedni] = str[xedni];
		xedni++;
	}
	result[++index] = NULL;
	if (rts != NULL)
	{
		index = 0;
		while (rts[index] != NULL)
			free(rts[index++]);
		free(rts);
	}
	free(str);
	return (result);
}

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
		exit(0);
	while (0 < 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		result = sl_join_map(result, line);
	}
	close(fd);
	return (result);
}