/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:42:06 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/27 01:50:49 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_words(const char *s, char c)
{
	int	index;
	int	word;

	index = 0;
	word = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			while (s[index] == c)
				index++;
		}
		else
		{	
			while (s[index] != c && s[index] != '\0')
				index++;
			word++;
		}
	}
	return (word);
}

void	ft_find_len(const char *s, char c, char **result)
{
	int	index;
	int	index1;
	int	word;

	index = 0;
	word = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c && s[index] != '\0')
			index++;
		if (s[index] == '\0')
			break ;
		index1 = 0;
		while (s[index] != c && s[index] != '\0')
		{
			index++;
			index1++;
		}
		result[word] = (char *)malloc(sizeof(char) * index1 + 1);
		word++;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		word;
	int		index;
	int		index1;

	word = ft_find_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (result == NULL)
		return (0);
	ft_find_len(s, c, result);
	index = 0;
	word = 0;
	while (s[index] != '\0')
	{
		index1 = 0;
		while (s[index] == c && s[index] != '\0')
			index++;
		if (s[index] == '\0')
			break ;
		while (s[index] != c && s[index] != '\0')
			result[word][index1++] = s[index++];
		result[word++][index1] = '\0';
	}
	result[word] = NULL;
	return (result);
}
