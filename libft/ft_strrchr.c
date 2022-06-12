/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:04:57 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/22 16:27:32 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		check;
	char	nc;

	nc = c;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == nc)
		{
			check = 1;
			while (s[index + check] != nc)
			{
				if (s[index + check] == '\0')
					return ((char *)&s[index]);
				check++;
			}
		}
		index++;
	}
	if (nc == '\0' && s[index] == '\0')
		return ((char *)&s[index]);
	return (0);
}
