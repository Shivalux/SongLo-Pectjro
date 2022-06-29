/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checkmap_misconfig.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:17:43 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/29 23:25:52 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_misconfig(char **map)
{
	int	len;
	int	i;

	i = 0;
	if (sl_checkcompair(map, NULL, 'P', 1) <= 0)
		return (100);
	if (sl_checkcompair(map, NULL, 'E', 1) <= 0)
		return (101);
	if (sl_checkcompair(map, NULL, 'C', 1) <= 0)
		return (102);
	len = sl_checklen(NULL, map[0], 2);
	while (map[i] != NULL)
	{
		if (sl_checklen(NULL, map[i], 2) != len)
			return (103);
		if (map[i][sl_checklen(NULL, map[i], 2) - 1] != '1')
			return (104);
		if (map[i++][0] != '1')
			return (104);
	}
	if (sl_checkcompair(NULL, map[0], '1', 2) != sl_checklen(NULL, map[0], 2) \
		|| sl_checkcompair(NULL, map[i - 1], '1', 2) != sl_checklen(NULL, \
			map[i - 1], 2))
		return (104);
	return (42);
}

void	sl_checkmap_misconfig(t_data *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		ft_printf("This map dosen't exist, please check the path agian.\n");
	else if (sl_check_misconfig(data->map) == 100)
		ft_printf("ERROR: This map dosen't contain the starting position.\n");
	else if (sl_check_misconfig(data->map) == 101)
		ft_printf("ERROR: This map dosen't contain the exit point.\n");
	else if (sl_check_misconfig(data->map) == 102)
		ft_printf("ERROR: This map need to be contain a collectible.\n");
	else if (sl_check_misconfig(data->map) == 103)
		ft_printf("ERROR: This map need to be rectangular.\n");
	else if (sl_check_misconfig(data->map) == 104)
		ft_printf("ERROR: This map need to be surrouned by the wall.\n");
	else
		return ;
	while (data->map != NULL && data->map[i] != NULL)
		free(data->map[i++]);
	if (data->map != NULL)
		free(data->map);
	free(data);
	exit(0);
}
