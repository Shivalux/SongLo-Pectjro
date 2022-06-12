/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:41:53 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/27 01:27:04 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index_c;

	index_c = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (src[index_c] != '\0' && index_c < dstsize - 1)
	{
		dst[index_c] = src[index_c];
		index_c++;
	}
	dst[index_c] = '\0';
	return (ft_strlen(src));
}
