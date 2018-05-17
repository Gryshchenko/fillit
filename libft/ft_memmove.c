/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgryshch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:07:02 by vgryshch          #+#    #+#             */
/*   Updated: 2017/11/27 12:43:10 by vgryshch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*d;

	d = (char *)dst;
	str = (char *)src;
	if (str < d)
	{
		while (len--)
		{
			d[len] = str[len];
		}
	}
	else
		ft_memcpy(d, src, len);
	return (d);
}
