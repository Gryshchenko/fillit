/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:27:00 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 16:30:33 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		free(head->content);
		head = head->next;
		free(temp);
	}
}
