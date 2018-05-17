/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:36:04 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 15:09:56 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_listlen(t_list *alst)
{
	t_list	*temp;
	int		counter;

	temp = alst;
	counter = 0;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
