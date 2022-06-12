/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:30:29 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 20:44:19 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystrack, const char *needle, size_t len)
{
	size_t	index;
	size_t	check;

	index = 0;
	if (needle[index] == '\0')
		return ((char *)haystrack);
	while (haystrack[index] != '\0' && index < len)
	{
		if (haystrack[index] == needle[0])
		{
			check = 0;
			while (haystrack[index + check] == needle[check]
				&& (index + check) < len)
			{
				if (needle[check + 1] == '\0')
				{
					return ((char *)&haystrack[index]);
				}
				check++;
			}
		}
		index++;
	}
	return (0);
}
