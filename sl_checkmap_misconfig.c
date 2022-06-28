/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checkmap_misconfig.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:17:43 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/27 17:36:04 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//int	sl_checkcomapair(char **rts, char *str, char c, int made);
//int sl_checklen(char **rts, char *str, int mode);

int	sl_check_misconfig(char **map)
{
	int	len;
	int	index;

	index = 0;
	if (sl_checkcompair(map, NULL, 'P', 1) <= 0)
		return (100);
	if (sl_checkcompair(map, NULL, 'E', 1) <= 0)
		return (101);
	if (sl_checkcompair(map, NULL, 'C', 1) <= 0)
		return (102);
	len = sl_checklen(NULL, map[0], 2);
	while (map[index] != NULL)
	{
		if (sl_checklen(NULL, map[index], 2) != len)
			return (103);
		if (map[index][sl_checklen(NULL, map[index], 2) - 1] != '1')
			return (104);
		if (map[index++][0] != '1')
			return (104);
	}
	if (sl_checkcompair(NULL, map[0], '1', 2) != sl_checklen(NULL, map[0], 2))
		return (104);
	if (sl_checkcompair(NULL, map[index - 1], '1', 2) != sl_checklen(NULL, map[index - 1], 2))
		return (104);
	return (42);
}


void sl_checkmap_misconfig(t_data *data)
{
	int	index;

	index = 0;
	if (data->map == NULL)
		write(1, "This map dosen't exist, please check the path agian.\n", 53);
	else if (sl_check_misconfig(data->map) == 100)
		write(1, "ERROR: This map dosen't contain the starting position.\n", 55);
	else if (sl_check_misconfig(data->map) == 101)
		write(1, "ERROR: This map dosen't contain the exit point.\n", 48);
	else if (sl_check_misconfig(data->map) == 102)
		write(1, "ERROR: This map need to be contain at lest 1 collectible.\n", 58);
	else if (sl_check_misconfig(data->map) == 103)
		write(1, "ERROR: This map need to be rectangular.\n", 40);
	else if (sl_check_misconfig(data->map) == 104)
		write(1, "ERROR: This map need to be surrouned by the wall.\n", 50);
	else
		return ;
	while(data->map != NULL && data->map[index] != NULL)
		free(data->map[index++]);
	if (data->map != NULL)
		free(data->map);
	free(data);
	exit(0);
}
