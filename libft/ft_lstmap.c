/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:55:29 by vgryshch          #+#    #+#             */
/*   Updated: 2017/12/03 17:12:58 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	fresh = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		if (list->next == NULL)
		{
			ft_free(list);
			return (NULL);
		}
		list = list->next;
	}
	return (fresh);
}
