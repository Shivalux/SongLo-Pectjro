/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:42:06 by sharnvon          #+#    #+#             */
/*   Updated: 2022/03/02 11:02:55 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	size_t			index;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	index = 0;
	if (n == 0)
	{
		return (0);
	}
	while (ss1[index] != '\0' && ss2[index] != '\0' && index < n)
	{
		if (ss1[index] != ss2[index])
		{
			return (ss1[index] - ss2[index]);
		}
		if (index == n - 1)
		{
			break ;
		}
		index++;
	}
	return (ss1[index] - ss2[index]);
}
