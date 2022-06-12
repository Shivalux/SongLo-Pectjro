/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:25:05 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 16:50:11 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (0);
	}
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
