/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:02:57 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/27 01:36:39 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*nsrc;
	size_t		index_c;
	char		*ndest;

	nsrc = src;
	ndest = dest;
	index_c = 0;
	if (ndest == NULL && nsrc == NULL)
		return (0);
	if (len == 0)
		return (dest);
	if (ndest < nsrc)
		ndest = ft_memcpy(dest, src, len);
	else
	{
		index_c = len - 1;
		while (index_c > 0)
		{
			ndest[index_c] = nsrc[index_c];
			index_c--;
		}
		if (index_c == 0)
			ndest[index_c] = nsrc[index_c];
	}
	return (dest);
}
