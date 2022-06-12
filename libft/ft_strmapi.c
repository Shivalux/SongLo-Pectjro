/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:05:39 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/26 12:58:45 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	index;
	char	*result;

	index = 0;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
	{
		return (0);
	}
	while (s[index] != '\0')
	{
		result[index] = (*f)(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
