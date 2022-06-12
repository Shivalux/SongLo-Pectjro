/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:22:16 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/22 23:40:41 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;
	size_t	slen;

	slen = ft_strlen(s);
	index = 0;
	if (len > slen)
		result = (char *)malloc (sizeof(char) * (slen + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	if (start > (unsigned int)slen)
	{
		result[index] = '\0';
		return (result);
	}
	while (index < len && s[index] != '\0')
	{
		result[index] = s[start];
		index++;
		start++;
	}
	result[index] = '\0';
	return (result);
}
