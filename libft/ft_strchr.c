/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:50:38 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/20 14:13:58 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	nc;

	nc = c;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == nc)
		{
			return ((char *)&s[index]);
		}
		index++;
	}
	if (nc == '\0' && s[index] == '\0')
	{
		return ((char *)&s[index]);
	}
	return (0);
}
