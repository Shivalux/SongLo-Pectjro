/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:42:55 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 21:19:02 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_dest;
	size_t	index_src;
	size_t	dst_len;

	index_dest = ft_strlen(dst);
	index_src = 0;
	dst_len = ft_strlen(dst);
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	if (dst_len > dstsize)
	{
		return (ft_strlen(src) + dstsize);
	}
	while (src[index_src] != '\0' && index_dest < dstsize - 1)
	{
		dst[index_dest] = src[index_src];
		index_dest++;
		index_src++;
	}
	dst[index_dest] = '\0';
	return (ft_strlen(src) + dst_len);
}
