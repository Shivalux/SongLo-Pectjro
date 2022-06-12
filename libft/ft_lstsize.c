/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:21:44 by sharnvon          #+#    #+#             */
/*   Updated: 2022/02/28 20:03:41 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*check;

	check = lst;
	count = 0;
	while (check != NULL)
	{
		check = check->next;
		count++;
	}
	return (count);
}
