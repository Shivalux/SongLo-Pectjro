/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:41:49 by sharnvon          #+#    #+#             */
/*   Updated: 2022/03/11 23:42:27 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(int size)
{
	char	*result;
	int		index;

	index = 0;
	result = (char *)malloc(size);
	if (result == NULL)
		return (0);
	while (index < size)
	{
		result[index] = '\0';
		index++;
	}
	return (result);
}

int	ft_strlen(char *str, int index)
{
	int	count;

	count = 0;
	if (index == 0)
	{
		while (str[count] != '\0' && str[count] != '\n')
		count++;
	}
	else if (index == 1)
	{
		while (str[count] != '\0')
		count++;
	}
	return (count);
}

int	ft_check_newline(char *temp)
{
	int	index;

	index = 0;
	while (temp[index] != '\0')
	{
		if (temp[index] == '\n')
		{
			return (1);
		}
		index++;
	}
	return (0);
}

char	*ft_result_assign(char *temp, char *result, t_read *brain)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
		result[len++] = temp[index++];
	if (temp[index] == '\n')
		index++;
	brain->cont = ft_checknstore_brain(result, temp, index, len);
	return (brain->cont);
}

int	ft_check_fd(int fd, t_read *brain)
{
	int	fds;

	fds = 0;
	while (fds < 10240)
	{
		if (fd == brain[fds].file)
			break ;
		fds++;
	}
	if (fd != brain[fds].file)
	{
		fds = 0;
		while (fds < 10240)
		{
			if (brain[fds].file <= 0)
			{
				brain[fds].file = fd;
				break ;
			}
			fds++;
		}
	}
	return (fds);
}
