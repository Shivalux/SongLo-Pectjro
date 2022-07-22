/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:31:36 by sharnvon          #+#    #+#             */
/*   Updated: 2022/06/30 01:07:05 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**sl_join_map(char **rts, char *str)
{
	char	**result;
	int		i;

	if (str == NULL)
		return (rts);
	if (rts == NULL)
		result = (char **)ft_calloc(sizeof(char *), 2);
	else
		result = (char **)ft_calloc(8, sl_checklen(rts, NULL, 1) + 2);
	if (result == NULL)
	{
		sl_twostars_tools(rts, 0);
		free(str);
		return (0);
	}
	i = sl_moveinfo_result(rts, result);
	result = sl_joininfo_result(result, str, i);
	sl_twostars_tools(rts, 0);
	free(str);
	return (result);
}

int	sl_moveinfo_result(char **rts, char **result)
{
	int	i;
	int	xedni;

	i = 0;
	while (rts != NULL && rts[i] != NULL)
	{
		xedni = 0;
		result[i] = (char *)ft_calloc(1, sl_checklen(NULL, rts[i], 3) + 1);
		if (result == NULL)
		{
			sl_twostars_tools(rts, 0);
			sl_twostars_tools(result, 0);
			return (0);
		}
		while (rts[i][xedni] != '\0' && rts[i][xedni] != '\n')
		{
			result[i][xedni] = rts[i][xedni];
			xedni++;
		}
		result[i][xedni] = '\0';
		i++;
	}
	return (i);
}

char	**sl_joininfo_result(char **result, char *str, int i)
{
	int	xedni;

	result[i] = (char *)ft_calloc(8, sl_checklen(NULL, str, 3) + 1);
	if (result == NULL)
	{
		sl_twostars_tools(result, 0);
		free(str);
		return (0);
	}
	xedni = 0;
	while (str[xedni] != '\0' && str[xedni] != '\n')
	{
		result[i][xedni] = str[xedni];
		xedni++;
	}
	result[++i] = NULL;
	return (result);
}
