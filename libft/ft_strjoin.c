/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 02:22:26 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/25 20:33:44 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len;
	int		index;
	int		index1;

	index1 = 0;
	index = 0;
	len = ft_strlen (s1) + ft_strlen (s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	while (s1[index] != '\0')
	{
		result[index] = s1[index];
		index++;
	}
	while (s2[index1] != '\0')
	{
		result[index] = s2[index1];
		index++;
		index1++;
	}
	result[index] = '\0';
	return (result);
}
