/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:33:04 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/18 23:55:36 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./getnextline/get_next_line.h"
#include "./libft/libft.h"


	/* counting function*/
		/* mode1 = count 2D malloc | mode2 = count lenght of a string |
		 mode3 = count until find newline in a string */
int	sl_checklen(char **rts, char *str, int mode)
{
	int	count;

	count = 0;
	if (mode == 1 && rts != NULL)
	{
		while (rts[count] != NULL)
			count++;
		return (count);
	}
	else if (mode == 2 && str != NULL)
	{
		while (str[count] != '\0')
			count++;
		return (count);
	}
	else if (mode == 3 && str != NULL)
	{
		while (str[count] != '\n' && str[count] != '\0')
			count++;
		return (count);
	}
	return (-1);
}

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
		exit (0);
	printf("fd = %d\n", fd);
	while (0 < 1)
	{
		line = get_next_line(fd);
		printf("line = %s\n", line);
		if (line == NULL)
			break ;
		result = sl_join_map(result, line);
	}

	int	count = 0;
	while (result[count] != NULL)
	{
		printf("map[count] ==> %s\n", result[count++]);
	}
	printf("====ENDING====\n");
	exit(0);


	

	close(fd);
	return (result);
}


int	main(int argc, char **argv)
{
	char **map;

	if (argc != 2)
	{	
		write(1, "WRONG ARGUMENT\n", 15);
		return (0);
	}
	map = sl_read_map(argv);
	return (0);
}
