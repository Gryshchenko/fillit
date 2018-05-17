/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:58:20 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 16:00:11 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listlast(t_list *alst)
{
	t_list	*find;

	find = alst;
	while (find)
	{
		while (find->next)
			find = find->next;
		return (find);
	}
	return (find);
}
