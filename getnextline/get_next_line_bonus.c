/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bkp3_get_next_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:07:45 by sharnvon          #+#    #+#             */
/*   Updated: 2022/03/11 23:30:20 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_info_tranfer(char *temp, char *info, int len)
{
	char	*result;
	int		index;
	int		xedni;

	index = 0;
	xedni = 0;
	result = ft_calloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (0);
	while ((temp != NULL && temp[index] != '\0'))
	{
		result[index] = temp[index];
		index++;
		len--;
	}
	while (len > 0)
	{
		result[index++] = info[xedni++];
		len--;
	}
	result[index] = '\0';
	if (temp == NULL)
		return (result);
	free(temp);
	return (result);
}

char	*ft_checknread_temp(int fd, char *temp, t_read *brain)
{
	int		len;

	len = 0;
	if (brain->cont != NULL && brain->cont[0] != '\0')
	{
		temp = ft_info_tranfer(temp, brain->cont, ft_strlen(brain->cont, 1));
		if (temp == NULL)
			return (0);
		free(brain->cont);
	}
	if (temp != NULL)
	{
		if (ft_check_newline(temp) == 1)
			return (temp);
		len = ft_strlen(temp, 1);
	}
	temp = ft_read_file(fd, temp, len);
	if (temp == NULL)
		return (0);
	return (temp);
}

char	*ft_read_file(int fd, char *temp, int len)
{
	int		byte;
	char	*info;

	byte = 0;
	info = ft_calloc(sizeof(char) * BUFFER_SIZE);
	if (info == NULL)
		return (0);
	while (1 > 0)
	{
		byte = read(fd, info, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		len = len + byte;
		temp = ft_info_tranfer(temp, info, len);
		if (temp == NULL)
		{
			free(info);
			return (0);
		}
		if (ft_check_newline(temp) == 1)
			break ;
	}
	free(info);
	return (temp);
}

char	*ft_checknstore_brain(char *result, char *temp, int index, int len)
{
	int		xedni;
	char	*brain;

	xedni = 0;
	brain = ft_calloc(sizeof(char) * ft_strlen(&temp[index], 1) + 1);
	if (brain == NULL)
		return (0);
	while (temp[index] != '\0')
		brain[xedni++] = temp[index++];
	brain[xedni] = '\0';
	if (brain == NULL || brain[0] == '\0')
	{
		if (temp[index - 1] == '\n')
			result[len++] = '\n';
		result[len] = '\0';
		free(temp);
		free(brain);
		brain = NULL;
		return (brain);
	}
	result[len] = '\n';
	result[len + 1] = '\0';
	free(temp);
	return (brain);
}

char	*get_next_line(int fd)
{
	char				*result;
	char				*temp;
	static t_read		brain[10240];
	int					fds;

	temp = NULL;
	fds = ft_check_fd(fd, brain);
	temp = ft_checknread_temp(fd, temp, &brain[fds]);
	if (temp == NULL)
	{
		brain[fds].file = 0;
		brain[fds].cont = NULL;
		return (0);
	}
	result = ft_calloc(sizeof(char) * ft_strlen(temp, 0) + 2);
	if (result == NULL)
		return (0);
	ft_result_assign(temp, result, &brain[fds]);
	if (brain[fds].cont == NULL)
		brain[fds].file = 0;
	return (result);
}
