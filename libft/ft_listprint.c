/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:30:50 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/30 14:32:59 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listprint(t_list *alst)
{
	t_list	*print;

	print = alst;
	while (print != NULL)
	{
		ft_putendl(print->content);
		print = print->next;
	}
}
