/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:44:43 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/27 22:29:44 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*count;

	count = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
		{
			(*lst) = (*lst)->next;
		}
		(*lst)->next = new;
		*lst = count;
	}
}
