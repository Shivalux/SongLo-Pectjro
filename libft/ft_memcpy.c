/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:43:05 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/27 01:25:28 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	const char	*nsrc;
	char		*ndest;
	size_t		index;

	nsrc = src;
	ndest = dst;
	index = 0;
	if (ndest == NULL && nsrc == NULL)
	{
		return (0);
	}
	while (index < n)
	{
		ndest[index] = nsrc[index];
		index++;
	}
	return (dst);
}
