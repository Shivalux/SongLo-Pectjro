/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:51:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 21:06:00 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*nb;

	nb = b;
	index = 0;
	while (index < len)
	{
		nb[index] = c;
		index++;
	}
	return (b);
}
