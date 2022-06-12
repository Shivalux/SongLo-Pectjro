/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:38:47 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 00:13:46 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cordition_trim(char const *s1, char const *set, char const *start)
{
	size_t		index;
	char		*result;

	index = 0;
	if (set[0] == '\0')
	{
		result = (char *)malloc(sizeof(char) * (ft_strlen(s1)));
		if (result == NULL)
			return (0);
		while (s1[index] != '\0')
		{
			result[index] = s1[index];
			index++;
		}
	}
	if ((s1[0] == '\0' && set[0] != '\0')
		|| (start[0] == '\0' && s1[0] != '\0'))
	{
		result = (char *)malloc(sizeof(char *) * 1);
		if (result == NULL)
			return (0);
	}
	result[index] = '\0';
	return (result);
}

char	*ft_front_trim(char const *s1, char const *set)
{
	size_t	check;
	size_t	index;

	check = 0;
	index = 0;
	while (set[check] != '\0')
	{
		if (s1[index] == set[check])
		{
			check = -1;
			index++;
		}
		check++;
	}
	return ((char *)&s1[index]);
}

char	*ft_rear_trim(char const *s1, char const *set)
{
	size_t	index;
	size_t	check;

	index = ft_strlen(s1) - 1;
	check = 0;
	while (set[check] != '\0')
	{
		if (s1[index] == set[check])
		{
			check = -1;
			index--;
		}
		check++;
	}
	return ((char *)&s1[index]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	char		*result;
	size_t		index;
	size_t		result_len;

	index = 0;
	start = ft_front_trim(s1, set);
	if (s1[0] == '\0' || set[0] == '\0' || start[0] == '\0')
	{
		result = ft_cordition_trim(s1, set, start);
		if (result == NULL)
			return (0);
		return (result);
	}
	result_len = (ft_strlen(start) - ft_strlen(ft_rear_trim(s1, set))) + 1;
	result = malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	while (index < result_len)
	{
		result[index] = start[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
