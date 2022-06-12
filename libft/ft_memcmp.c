/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:14:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/22 16:30:11 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	int					result;
	const unsigned char	*sr1;
	const unsigned char	*sr2;

	sr1 = s1;
	sr2 = s2;
	result = 0;
	index = 0;
	while (index < n)
	{
		if (sr1[index] != sr2[index])
		{
			result = sr1[index] - sr2[index];
			return (result);
		}
		index++;
	}
	return (result);
}
