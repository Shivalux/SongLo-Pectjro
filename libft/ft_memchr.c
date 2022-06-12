/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:37:08 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/22 16:29:11 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;
	const char	*ns;
	char		c1;

	c1 = c;
	ns = s;
	index = 0;
	while (index < n)
	{
		if (ns[index] == c1)
		{
			return ((char *)&ns[index]);
		}
		index++;
	}
	return (0);
}
