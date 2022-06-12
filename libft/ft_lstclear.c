/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:18:56 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 20:07:06 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*checkpoint;

	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			checkpoint = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = checkpoint;
		}
	}
}
